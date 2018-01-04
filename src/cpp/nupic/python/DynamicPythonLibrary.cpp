  class DynamicPythonLibrary
  {
    typedef void (*initPythonFunc)();
    typedef void (*finalizePythonFunc)();
    typedef void * (*createSpecFunc)(const char *, void **, const char *);
    typedef int (*destroySpecFunc)(const char *, const char *);
    typedef void * (*createPyNodeFunc)(const char *, void *, void *, void **, const char *);
    typedef void * (*deserializePyNodeFunc)(const char *, void *, void *, void *, const char *);
    typedef void * (*deserializePyNodeProtoFunc)(const char *, void *, void *, void *, const char *);
  public:
    DynamicPythonLibrary() :
      initPython_(nullptr),
      finalizePython_(nullptr),
      createSpec_(nullptr),
      destroySpec_(nullptr),
      createPyNode_(nullptr)
    {
        initPython_ = (initPythonFunc)PyBindRegion::NTA_initPython;
        finalizePython_ = (finalizePythonFunc)PyBindRegion::NTA_finalizePython;
        createPyNode_ = (createPyNodeFunc)PyBindRegion::NTA_createPyNode;
        deserializePyNode_ = (deserializePyNodeFunc)PyBindRegion::NTA_deserializePyNode;
        deserializePyNodeProto_ = (deserializePyNodeProtoFunc)PyBindRegion::NTA_deserializePyNodeProto;
        createSpec_ = (createSpecFunc)PyBindRegion::NTA_createSpec;
        destroySpec_ = (destroySpecFunc)PyBindRegion::NTA_destroySpec;

      (*initPython_)();
    }

    ~DynamicPythonLibrary()
    {
      if (finalizePython_)
        finalizePython_();
    }

    void * createSpec(std::string nodeType, void ** exception, std::string className)
    {
      return (*createSpec_)(nodeType.c_str(), exception, className.c_str());
    }

    int destroySpec(std::string nodeType, std::string& className)
    {
      NTA_INFO << "destroySpec(" << nodeType << ")";
      return (*destroySpec_)(nodeType.c_str(), className.c_str());
    }

    void * createPyNode(const std::string& nodeType,
                        ValueMap * nodeParams,
                        Region * region,
                        void ** exception,
                        const std::string& className)
    {
      return (*createPyNode_)(nodeType.c_str(),
                              reinterpret_cast<void *>(nodeParams),
                              reinterpret_cast<void*>(region),
                              exception,
                              className.c_str());

    }

    void * deserializePyNode(const std::string& nodeType,
                             BundleIO* bundle,
                             Region * region,
                             void ** exception,
                             const std::string& className)
    {
      return (*deserializePyNode_)(nodeType.c_str(),
                                   reinterpret_cast<void*>(bundle),
                                   reinterpret_cast<void*>(region),
                                   exception,
                                   className.c_str());
    }

    void * deserializePyNodeProto(const std::string& nodeType,
                                  capnp::AnyPointer::Reader* proto,
                                  Region * region,
                                  void ** exception,
                                  const std::string& className)
    {
      return (*deserializePyNodeProto_)(nodeType.c_str(),
                                        reinterpret_cast<void*>(proto),
                                        reinterpret_cast<void*>(region),
                                        exception,
                                        className.c_str());
    }

    const std::string& getRootDir() const
    {
      return rootDir_;
    }

  private:
    std::string rootDir_;
    boost::shared_ptr<DynamicLibrary> pynodeLibrary_;
    initPythonFunc initPython_;
    finalizePythonFunc finalizePython_;
    createSpecFunc createSpec_;
    destroySpecFunc destroySpec_;
    createPyNodeFunc createPyNode_;
    deserializePyNodeFunc deserializePyNode_;
    deserializePyNodeProtoFunc deserializePyNodeProto_;
  };
  
  
  
  
// This function creates either a NuPIC 2 or NuPIC 1 Python node
static RegionImpl * createPyNode(DynamicPythonLibrary * pyLib,
                                 const std::string & nodeType,
                                 ValueMap * nodeParams,
                                 Region * region)
{
  std::string className(nodeType.c_str() + 3);
  for (auto pyr=pyRegions.begin(); pyr!=pyRegions.end(); pyr++)
  {
    const std::string module = pyr->first;
    std::set<std::string> classes = pyr->second;

    // This module contains the class
    if (classes.find(className) != classes.end())
    {
      void * exception = nullptr;
      void * node = pyLib->createPyNode(module, nodeParams, region, &exception, className);
      if (node)
      {
        return static_cast<RegionImpl*>(node);
      }
    }
  }

  NTA_THROW << "Unable to create region " << region->getName() << " of type " << className;
  return nullptr;
}

// This function deserializes either a NuPIC 2 or NuPIC 1 Python node
static RegionImpl * deserializePyNode(DynamicPythonLibrary * pyLib,
                                      const std::string & nodeType,
                                      BundleIO & bundle,
                                      Region * region)
{
  std::string className(nodeType.c_str() + 3);
  for (auto pyr=pyRegions.begin(); pyr!=pyRegions.end(); pyr++)
  {
    const std::string module = pyr->first;
    std::set<std::string> classes = pyr->second;

    // This module contains the class
    if (classes.find(className) != classes.end())
    {
      void * exception = nullptr;
      void * node = pyLib->deserializePyNode(module, &bundle, region, &exception, className);
      if (node)
      {
        return static_cast<RegionImpl*>(node);
      }
    }
  }

  NTA_THROW << "Unable to deserialize region " << region->getName() << " of type " << className;
  return nullptr;



}

RegionImpl* RegionImplFactory::createRegionImpl(const std::string nodeType,
                                                const std::string nodeParams,
                                                Region* region)
{

  RegionImpl *impl = nullptr;
  Spec *ns = getSpec(nodeType);
  ValueMap vm = YAMLUtils::toValueMap(
    nodeParams.c_str(),
    ns->parameters,
    nodeType,
    region->getName());

  if (cppRegions.find(nodeType) != cppRegions.end())
  {
    impl = cppRegions[nodeType]->createRegionImpl(vm, region);
  }
  else if ((nodeType.find(std::string("py.")) == 0))
  {
    if (!pyLib_)
      pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    impl = createPyNode(pyLib_.get(), nodeType, &vm, region);
  } else
  {
    NTA_THROW << "Unsupported node type '" << nodeType << "'";
  }

  return impl;

}

RegionImpl* RegionImplFactory::deserializeRegionImpl(const std::string nodeType,
                                                     BundleIO& bundle,
                                                     Region* region)
{

  RegionImpl *impl = nullptr;

  if (cppRegions.find(nodeType) != cppRegions.end())
  {
    impl = cppRegions[nodeType]->deserializeRegionImpl(bundle, region);
  }
  else if (StringUtils::startsWith(nodeType, "py."))
  {
    if (!pyLib_)
      pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    impl = deserializePyNode(pyLib_.get(), nodeType, bundle, region);
  } else
  {
    NTA_THROW << "Unsupported node type '" << nodeType << "'";
  }
  return impl;

}

// This function returns the node spec of a NuPIC 2 or NuPIC 1 Python node
static Spec * getPySpec(DynamicPythonLibrary * pyLib,
                                const std::string & nodeType)
{
  std::string className(nodeType.c_str() + 3);
  for (auto pyr=pyRegions.begin(); pyr!=pyRegions.end(); pyr++)
  {
    const std::string module = pyr->first;
    std::set<std::string> classes = pyr->second;

    // This module contains the class
    if (classes.find(className) != classes.end())
    {
      void * exception = nullptr;
      void * ns = pyLib->createSpec(module, &exception, className);
      if (exception != nullptr)
      {
        throw *((Exception*)exception);
      }
      if (ns)
      {
        return (Spec *)ns;
      }
    }
  }

  NTA_THROW << "Matching Python module for " << className << " not found.";
}

Spec * RegionImplFactory::getSpec(const std::string nodeType)
{
  std::map<std::string, Spec*>::iterator it;
  // return from cache if we already have it
  it = nodespecCache_.find(nodeType);
  if (it != nodespecCache_.end())
    return it->second;

  // grab the nodespec and cache it
  // one entry per supported node type
  Spec * ns = nullptr;
  if (cppRegions.find(nodeType) != cppRegions.end())
  {
    ns = cppRegions[nodeType]->createSpec();
  }
  else if (nodeType.find(std::string("py.")) == 0)
  {
    if (!pyLib_)
      pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    ns = getPySpec(pyLib_.get(), nodeType);
  }
  else
  {
    NTA_THROW << "getSpec() -- Unsupported node type '" << nodeType << "'";
  }

  if (!ns)
    NTA_THROW << "Unable to get node spec for: " << nodeType;

  nodespecCache_[nodeType] = ns;
  return ns;
}

void RegionImplFactory::cleanup()
{
  std::map<std::string, Spec*>::iterator ns;
  // destroy all nodespecs
  for (ns = nodespecCache_.begin(); ns != nodespecCache_.end(); ns++)
  {
    assert(ns->second != nullptr);
    // PyNode node specs are destroyed by the C++ PyNode
    if (ns->first.substr(0, 3) == "py.")
    {
      std::string noClass = "";
      pyLib_->destroySpec(ns->first, noClass);
    }
    else
    {
      delete ns->second;
    }

    ns->second = nullptr;
  }

  nodespecCache_.clear();

  // destroy all RegisteredRegionImpls
  for (auto rri = cppRegions.begin(); rri != cppRegions.end(); rri++)
  {
    NTA_ASSERT(rri->second != nullptr);
    delete rri->second;
    rri->second = nullptr;
  }

  cppRegions.clear();
  initializedRegions = false;

  // Never release the Python dynamic library!
  // This is due to cleanup issues of Python itself
  // See: http://docs.python.org/c-api/init.html#Py_Finalize
  //pyLib_.reset();
}

  
  
  
  
  
  