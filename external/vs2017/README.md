# Visual Studio 2017 solution

ONLY 64BIT is supported!

This solution contains all c++ related projects.

## nupic.core

Dependencies (if not header only, then linked statically):
* Boost (1.66)
* zlib
* yaml-cpp


Debug Compile Settings:
* Preprocessor: NTA_OS_WINDOWS;NTA_COMPILER_MSVC;_CRT_SECURE_NO_WARNINGS;_SCL_SECURE_NO_WARNINGS;BOOST_ALL_NO_LIB
* Program Database (/Zi)
* Warning Level 3 (/W3)
* No SDL checks (/sdl-)

Removals:

* capn proto
    - capnp::AnyPointer
    - base class stuff:  public Serializable<XXX>
    - virtual void write(capnp::AnyPointer::Builder& anyProto) const override;
    - virtual void read(capnp::AnyPointer::Reader& anyProto) override;

* os related ifdef's (will be switching to boost)

* no py_support or for that matter no python C API calls.


Output: Static Lib: nupic.core.lib

All the base classes but NO other languages related bindings. For such please have a look at nupic.bindingss.


## nupic.core_test

Dependencies (if not header only, then linked statically):
* gtest

Debug Compile Settings:
* Preprocessor: _DEBUG;_CONSOLE;_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING;BOOST_ALL_NO_LIB;NTA_OS_WINDOWS;
* Program Database (/Zi)
* Warning Level 3 (/W3)
* No SDL checks (/sdl-)



## nupic.bindings

Output: Dynamic Lib: bindings.pyd

Interface code to be accessed by python 3. For python 2.7 have a look a nupic.bindings_2.7


## nupic.bindings_2.7

Output: Dynamic Lib: bindings.pyd

Interface code to be accessed by python 2.7. It essentially the same as nupic.bindings but including python 2.7 code.


## yaml-cpp