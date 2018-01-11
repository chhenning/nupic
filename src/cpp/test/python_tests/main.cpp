#include <pybind11/pybind11.h>
#include <pybind11/embed.h>


#include <nupic/engine/Network.hpp>

using namespace nupic;
namespace py = pybind11;

int main()
{

    // not needed since PyBindRegion is already initializing python interpreter, via initialize_interpreter
    //py::scoped_interpreter guard{};
    try
    {
        std::cout << "Creating network..." << std::endl;
        Network n;

        std::cout << "Region count is " << n.getRegions().getCount() << "" << std::endl;

        std::cout << "Adding a PyNode region..." << std::endl;
        Network::registerPyBindRegion("nupic.regions.TestNode", "TestNode");
        auto level2 = n.addRegion("level2", "py.TestNode", "{int32Param: 444}");
    }
    catch (py::error_already_set& e)
    {
        std::cout << e.what() << std::endl;
    }



    //std::cout << "Region count is " << n.getRegions().getCount() << "" << std::endl;
    //std::cout << "Node type: " << level2->getType() << "" << std::endl;
    //std::cout << "Nodespec is:\n" << level2->getSpec()->toString() << "" << std::endl;

    //Real64 rval;
    //std::string int64Param("int64Param");
    //std::string real64Param("real64Param");

    //// get the value of intArrayParam after the setParameter call.

    //// --- Test getParameterReal64 of a PyNode
    //rval = level2->getParameterReal64("real64Param");
    //NTA_CHECK(rval == 64.1);
    //std::cout << "level2 getParameterReal64() returned: " << rval << std::endl;


    return 0;
}