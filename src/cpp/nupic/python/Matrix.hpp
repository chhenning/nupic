/* ---------------------------------------------------------------------
* Numenta Platform for Intelligent Computing (NuPIC)
* Copyright (C) 2013, Numenta, Inc.  Unless you have an agreement
* with Numenta, Inc., for a separate license for this software code, the
* following terms and conditions apply:
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU Affero Public License for more details.
*
* You should have received a copy of the GNU Affero Public License
* along with this program.  If not, see http://www.gnu.org/licenses.
*
* http://numenta.org/licenses/
* ---------------------------------------------------------------------
*/

#ifndef NUPIC_EXT_BINDINGS_MATRIX_HPP
#define NUPIC_EXT_BINDINGS_MATRIX_HPP

#include <pybind11/numpy.h>

namespace nupic_ext {

    // Simple wrapper to mirror NumpyMatrix members
    template<typename T = float>
    class Numpy_Matrix
    {
    public:
        Numpy_Matrix(const pybind11::buffer_info& bi)
            : _bi(bi.ptr, bi.itemsize, bi.format, bi.ndim, bi.shape, bi.strides)
        {}

        int nRows() const { return _bi.shape[0]; }
        int nCols() const { return _bi.shape[1]; }

        T get(int r, int c) const
        {
            auto p = (char*)_bi.ptr + (_bi.strides[0] * r) + (_bi.strides[1] * c);
            auto element_ptr = (T*)p;

            return *element_ptr;
        }

    private:

        pybind11::buffer_info _bi;
    };

    // Simple wrapper to mirror NumpyMatrix members
    template<typename T = float>
    class Numpy_Matrix2
    {
    public:
        Numpy_Matrix2(const std::uint32_t nRows, const std::uint32_t nCols)
            : _matrix({nRows, nCols})
        {}

        int nRows() const { return _matrix.shape(0); }
        int nCols() const { return _matrix.shape(1); }

        //T get(int r, int c) const
        //{
        //    auto p = (char*)_bi.ptr + (_bi.strides[0] * r) + (_bi.strides[1] * c);
        //    auto element_ptr = (T*)p;

        //    return *element_ptr;
        //}

    private:

        pybind11::array_t<T> _matrix;
    };

} // nupic_ext


#endif // NUPIC_EXT_BINDINGS_MATRIX_HPP




