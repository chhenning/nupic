#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include <nupic/os/Timer.hpp>

#include <nupic/engine/Network.hpp>
#include <nupic/engine/Region.hpp>


using namespace nupic;
namespace py = pybind11;

void test_PyBindRegion();

int main()
{
    // not needed since PyBindRegion is already initializing python interpreter, via initialize_interpreter
    ////py::scoped_interpreter guard{};
    //try
    //{
    //    test_PyBindRegion();
    //}
    //catch (py::error_already_set& e)
    //{
    //    std::cout << e.what() << std::endl;
    //}


    py::scoped_interpreter guard{};

    try
    {
        // Work around: AttributeError: module 'sys' has no attribute 'argv'
        py::exec(R"(
            import sys
            
            if not hasattr(sys, 'argv'):
                sys.argv = ['']

        )");

        py::eval_file(R"(D:\nupic\src\python\python3\test.py)");
    }
    catch (const py::error_already_set& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unexpected error." << std::endl;
    }


        return 0;
}