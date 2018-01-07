
#include <fstream>

#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/math/SparseMatrix.hpp>

#include "py_utils.hpp"

namespace py = pybind11;

typedef nupic::SparseMatrix<nupic::UInt32, nupic::Real32, nupic::Int32, nupic::Real64, nupic::DistanceToZero<nupic::Real32>> SparseMatrix32_t;
typedef nupic::SparseMatrix<nupic::UInt32, nupic::Real64, nupic::Int32, nupic::Real64, nupic::DistanceToZero<nupic::Real64>> _SparseMatrix64;

namespace nupic_ext
{
    void init_array_algo(py::module& m)
    {
        // count_gt
        m.def("count_gt", [](py::array_t<nupic::Real32>& x, nupic::Real32 threshold)
        {
            return nupic::count_gt(get_it(x), get_end(x), threshold);
        });

        // count_gte
        m.def("count_gte", [](py::array_t<nupic::Real32>& x, nupic::Real32 threshold)
        {
            return nupic::count_gte(get_it(x), get_end(x), threshold);
        });

        // count_lt
        m.def("count_lt", [](py::array_t<nupic::Real32>& x, nupic::Real32 threshold)
        {
            return nupic::count_lt(get_it(x), get_end(x), threshold);
        });

        // partialArgsort
        m.def("partialArgsort", [](size_t k, py::array_t<nupic::Real32>& x, py::array_t<nupic::UInt32>& r, int direction)
        {
            return nupic::partial_argsort(k, get_it(x), get_end(x), get_it(r), get_end(r), direction);
        }, "", py::arg("k"), py::arg("x"), py::arg("r"), py::arg("direction") = -1);

        // positiveLearningPartialArgsort
        m.def("positiveLearningPartialArgsort", [](size_t k, py::array_t<nupic::Real32>& x, py::array_t<nupic::UInt32>& r, nupic::Random& rng, bool real_random)
        {
            return nupic::partial_argsort_rnd_tie_break(k, get_it(x), get_end(x), get_it(r), get_end(r), rng, real_random);
        }, "", py::arg("k"), py::arg("x"), py::arg("r"), py::arg("rng"), py::arg("real_random") = false);

        // logicalAnd
        m.def("logicalAnd", [](py::array_t<nupic::Real32>& x, py::array_t<nupic::Real32>& y)
        {
            py::array_t<nupic::Real32> z(x.size());

            nupic::logical_and(get_it(x), get_end(x), get_it(y), get_end(y), get_it(z), get_end(z));

            return z;
        });

        // logicalAnd2
        m.def("logicalAnd2", [](py::array_t<nupic::Real32>& x, py::array_t<nupic::Real32>& y)
        {
            nupic::in_place_logical_and(get_it(x), get_end(x), get_it(y), get_end(y));
        });
    }

    void init_SM32(py::module& m)
    {
        py::class_<SparseMatrix32_t> sm(m, "SM32");

        sm.def(py::init<>())
            .def(py::init<nupic::UInt32, nupic::UInt32>(), py::arg("nrows"), py::arg("ncols"));

        // constructor from numpy array
        sm.def(py::init(
            [](py::array_t<nupic::UInt32>& a)
        {
            if (a.ndim() != 2) { throw std::runtime_error("Number of dimensions must be two."); }

            const nupic::UInt32* it = (const nupic::UInt32*) a.request().ptr;

            SparseMatrix32_t s(a.shape(0), a.shape(1), it);

            return s;
        }));

        sm.def("__add", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.add(val); });
        sm.def("__multiply", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.multiply(val); });
        sm.def("__subtract", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.subtract(val); });
        sm.def("__divide", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.divide(val); });
        
        sm.def("copy", [](SparseMatrix32_t& sm, SparseMatrix32_t& other) { sm.copy(other); });

        sm.def("isZero", &SparseMatrix32_t::isZero);

        sm.def("nRows", &SparseMatrix32_t::nRows);
        sm.def("nCols", &SparseMatrix32_t::nCols);


        sm.def("fromDense",
            [](SparseMatrix32_t& sm, py::array_t<nupic::Real>& matrix)
        {
            if (matrix.ndim() != 2) { throw std::runtime_error("Number of dimensions must be two."); }

            sm.fromDense(matrix.shape(0), matrix.shape(1), get_it(matrix));
        });

        sm.def("toDense",
            [](const SparseMatrix32_t& sm)
        {
            auto out = py::array_t<nupic::UInt32>({ sm.nRows(), sm.nCols() });
            nupic::UInt32* data = (nupic::UInt32*) out.request().ptr;

            sm.toDense(data);
            return out;
        });

        sm.def("setRowFromDense", [](SparseMatrix32_t& sm, nupic::UInt row, py::array_t<nupic::Real> r)
        {
            sm.setRowFromDense(row, get_it(r));
        });

        sm.def("setRowFromSparse", [](SparseMatrix32_t& sm, nupic::UInt row, py::array_t<nupic::UInt32>& ind, py::array_t<nupic::Real32>& nz)
        {
            sm.setRowFromSparse(row, get_it(ind), get_end(ind), get_it(nz));
        });

        sm.def("initializeWithFixedNNZR", [](SparseMatrix32_t self, nupic::UInt32 nnzr, nupic::Real32 v, nupic::UInt32 mode, nupic::UInt32 seed)
        {
            self.initializeWithFixedNNZR(nnzr, v, mode, seed);
        }, "Initialize a sparse matrix with a fixed number of non-zeros on each row."
            , py::arg("nnzr"), py::arg("v") = 1.0, py::arg("mode") = 0, py::arg("seed") = 42);

        sm.def("addRow", [](SparseMatrix32_t self, py::array_t<nupic::Real32>& row)
        {
            self.addRow(get_it(row));
        });

        sm.def("addRowNZ", [](SparseMatrix32_t self, py::array_t<nupic::UInt32>& ind, py::array_t<nupic::Real32>& nz, bool zero_permissive)
        {
            self.addRow(get_it(ind), get_end(ind), get_it(nz), zero_permissive);
        }, "", py::arg("ind"), py::arg("nz"), py::arg("zero_permissive") = false);


        sm.def("rowSums", [](const SparseMatrix32_t self)
        {
            py::array_t<nupic::Real32> m(self.nRows());

            self.rowSums(get_it(m));

            return m;
        });

        // rightVecSumAtNZ
        sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t self, py::array_t<nupic::Real32>& denseArray)
        {
            py::array_t<nupic::Real32> out(self.nRows());
            self.rightVecSumAtNZ(get_it(denseArray), get_it(out));

            return out;
        });


        sm.def("binaryLoadFromFile",
            [](SparseMatrix32_t& sm, const std::string filename)
        {
            std::ifstream load_file(filename.c_str());
            sm.fromBinary(load_file);
            load_file.close();
        });


        sm.def("binarySaveToFile",
            [](SparseMatrix32_t& sm, const std::string filename)
        {
            std::ofstream save_file(filename.c_str());
            sm.toBinary(save_file);
            save_file.close();
        });


        sm.def("getRow", [](SparseMatrix32_t& sm, nupic::UInt row)
        {
            const auto ncols = sm.nCols();
            py::array_t<nupic::Real> dense_row(ncols);
            sm.getRowToDense(row, get_it(dense_row));

            return dense_row;
        });
    }

} // namespace nupix_ext
