!!! THIS PROJECT IS WORK IN PROGRESS !!!


# nupic
Community Fork of Numenta Platform for Intelligent Computing (NuPIC)

The vast majority of the code is from Numenta's [repositories](https://github.com/numenta).

# Differences to Numenta's nupic implementation

Reducing external dependencies and embracing modern c++ concepts. For instance, all Python C API calls are removed and (pybind11)[] is used to ensure compatibility with python 2.7x and 3.x.

## Dependencies

Removals:
- Python C API
- apr
- apr-utils
- Capn Proto
- Swig


Additions
+ pybind11
+ more modern c++, like chrono
+ more boost, like filesystem, string algorithm
+ eigen or Blaze for matrix stuff


## Code changes

- Remove nupic data types like NTA_Byte, NTA_Int32, etc. Instead use c++11 types.
- Remove compiler warnings to a minimum.

