
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
    void init_SM32(py::module& m)
    {
        py::class_<SparseMatrix32_t> sm(m, "SM32");

        // create an alias for SM32
        m.attr("SparseMatrix") = sm;


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


        //void addCol(PyObject *col)
        sm.def("addCol", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& x)
        {
            sm.addCol(get_it(x));
        });

        //void addColNZ(PyObject *ind, PyObject *nz)
        sm.def("addColNZ", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& ind, py::array_t<nupic::Real32>& nz)
        {
            sm.addCol(get_it(ind), get_end(ind), get_it(nz));
        });

        //void deleteRows(PyObject *rowIndices)
        sm.def("deleteRows", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rowIndices)
        {
            sm.deleteRows(get_it(rowIndices), get_end(rowIndices));
        });

        //void deleteCols(PyObject *colIndices)
        sm.def("deleteCols", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& colIndices)
        {
            sm.deleteCols(get_it(colIndices), get_end(colIndices));
        });

        // getRow
        sm.def("getRow", [](SparseMatrix32_t& sm, nupic::UInt32 row)
        {
            const auto ncols = sm.nCols();
            py::array_t<nupic::Real32> dense_row(ncols);
            sm.getRowToDense(row, get_it(dense_row));

            return dense_row;
        });


        //PyObject* getCol(nupic::UInt ## N1 col) const
        sm.def("getCol", [](const SparseMatrix32_t& sm, nupic::UInt32 col)
        {
            py::array_t<nupic::Real32> dense_col(sm.nRows());
            sm.getColToDense(col, get_it(dense_col));
            
            return dense_col;
        });

        //PyObject* getDiagonal() const
        sm.def("getDiagonal", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> diag(sm.nRows());
            sm.getDiagonalToDense(get_it(diag));

            return diag;
        });

        //PyObject* rowNonZeros(nupic::UInt ## N1 row) const
        sm.def("rowNonZeros", [](const SparseMatrix32_t& sm, nupic::UInt32 row)
        {
            const auto n = sm.nNonZerosOnRow(row);
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(sm.nRows());
            sm.getRowToSparse(row, get_it(ind), get_it(val));

            return py::make_tuple(ind, val);
        });

        //PyObject* rowNonZeroIndices(nupic::UInt ## N1 row) const
        sm.def("rowNonZeroIndices", [](const SparseMatrix32_t& sm, nupic::UInt32 row)
        {
            const auto n = sm.nNonZerosOnRow(row);
            py::array_t<nupic::UInt32> ind(n); 
            
            sm.getRowIndicesToSparse(row, get_it(ind));
            
            return ind;
        });

        //PyObject* colNonZeros(nupic::UInt ## N1 col) const
        sm.def("colNonZeros", [](const SparseMatrix32_t& sm, nupic::UInt32 col)
        {
            const auto n = sm.nNonZerosOnCol(col);
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(n);
            
            sm.getColToSparse(col, get_it(ind), get_it(val));

            return py::make_tuple(ind, val);
        });

        //PyObject* nonZeroRows() const
        sm.def("nonZeroRows", [](const SparseMatrix32_t& sm)
        {
            const auto nNonZeroRows = sm.nNonZeroRows();
            py::array_t<nupic::UInt32> nzRows(nNonZeroRows);
            sm.nonZeroRows(get_it(nzRows));
            
            return nzRows;
        });

        //PyObject* zeroRows() const
        sm.def("zeroRows", [](const SparseMatrix32_t& sm)
        {
            const auto nZeroRows = sm.nZeroRows();
            py::array_t<nupic::UInt32> zRows(nZeroRows);
            sm.zeroRows(get_it(zRows));

            return zRows;
        });

        //PyObject* nonZeroCols() const
        sm.def("nonZeroCols", [](const SparseMatrix32_t& sm)
        {
            const auto nNonZeroCols = sm.nNonZeroCols();
            py::array_t<nupic::UInt32> nzCols(nNonZeroCols);

            sm.nonZeroCols(get_it(nzCols));

            return nzCols;
        });

        //PyObject* zeroCols() const
        sm.def("zeroCols", [](const SparseMatrix32_t& sm)
        {
            const auto nZeroCols = sm.nZeroCols();
            py::array_t<nupic::UInt32> zCols(nZeroCols);
            
            sm.zeroCols(get_it(zCols));

            return zCols;
        });

        //PyObject* zeroRowAndCol() const
        sm.def("zeroRowAndCol", [](const SparseMatrix32_t& sm)
        {
            std::vector<nupic::UInt32> zrc;
            nupic::UInt32 c = sm.zeroRowAndCol(std::back_inserter(zrc));

            py::array_t<nupic::UInt32> toReturn(c);
            std::copy(zrc.begin(), zrc.end(), get_it(toReturn));

            return toReturn;
        });

        ////void setElements(PyObject* py_i, PyObject* py_j, PyObject* py_v)
        //sm.def("setElements", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, py::array_t<nupic::UInt32>& v)
        //{
        //    const nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    const nupic::NumpyVectorT<nupic::Real ## N2> v(py_v);
        //    self->setElements(i.begin(), i.end(), j.begin(), v.begin());
        //});

        ////PyObject* getElements(PyObject* py_i, PyObject* py_j) const
        //sm.def("getElements", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j)
        //{
        //    const nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    nupic::NumpyVectorT<nupic::Real ## N2> v(i.size());
        //    self->getElements(i.begin(), i.end(), j.begin(), v.begin());
        //    return v.forPython();
        //});

        ////void setOuter(PyObject* py_i, PyObject* py_j, PyObject* py_v)
        //sm.def("setOuter", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, py::array_t<nupic::UInt32>& v)
        //{
        //    const nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    const nupic::NumpyMatrixT<nupic::Real ## N2> v(py_v);
        //    self->setOuter(i.begin(), i.end(), j.begin(), j.end(), v);
        //}, "Sets on the outer product of the passed ranges.");

        ////SparseMatrix ## N2 getOuter(PyObject* py_i, PyObject* py_j) const
        //sm.def("getOuter", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j)
        //{
        //    const nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    SparseMatrix ## N2 v(i.size(), j.size());
        //    self->getOuter(i.begin(), i.end(), j.begin(), j.end(), v);
        //    return v;
        //}, "Get on the outer products of the passed ranges.");

        ////PyObject* getAllNonZeros(bool three_lists = false) const
        //sm.def("getAllNonZeros", [](const SparseMatrix32_t& sm, bool three_lists)
        //{
        //    const nupic::UInt ## N1 nnz = self->nNonZeros();
        //    nupic::NumpyVectorT<nupic::UInt ## N1> rows(nnz), cols(nnz);
        //    nupic::NumpyVectorT<nupic::Real ## N2> vals(nnz);

        //    self->getAllNonZeros(rows.begin(), cols.begin(), vals.begin());

        //    PyObject* toReturn = NULL;

        //    if (!three_lists) {
        //        // Return one list of triples
        //        toReturn = PyTuple_New(nnz);
        //        for (nupic::UInt ## N1 i = 0; i != nnz; ++i) {
        //            PyObject* tuple = nupic::createTriplet ## N1(rows.get(i), cols.get(i), vals.get(i));
        //            PyTuple_SET_ITEM(toReturn, i, tuple);
        //        }
        //    }
        //    else {
        //        // Return three lists
        //        toReturn = PyTuple_New(3);
        //        PyTuple_SET_ITEM(toReturn, 0, rows.forPython());
        //        PyTuple_SET_ITEM(toReturn, 1, cols.forPython());
        //        PyTuple_SET_ITEM(toReturn, 2, vals.forPython());
        //    }

        //    return toReturn;
        //}, "Returns the positions and values of all the non-zeros stored in this matrix. The result can be either three lists ((i), (j), (v)) or one list of triples (i,j,v)."
        //, py::arg("three_lists") = false);

        ////void setAllNonZeros(nupic::UInt ## N1 nrows, nupic::UInt ## N1 ncols, PyObject* py_i, PyObject* py_j, PyObject* py_v, bool sorted = true)
        //sm.def("setAllNonZeros", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    nupic::NumpyVectorT<nupic::Real ## N2> v(py_v);
        //    self->setAllNonZeros(nrows, ncols,
        //        i.begin(), i.end(),
        //        j.begin(), j.end(),
        //        v.begin(), v.end(),
        //        sorted);
        //}, "", py::arg("nrows"), py::arg("ncols"), py::arg("i"), py::arg("j"), py::arg("v"), py::arg("sorted") = true);

        ////PyObject* getNonZerosInBox(nupic::UInt ## N1 row_begin, nupic::UInt ## N1 row_end, nupic::UInt ## N1 col_begin, nupic::UInt ## N1 col_end) const
        //sm.def("getNonZerosInBox", [](const SparseMatrix32_t& sm)
        //{
        //    std::vector<nupic::UInt ## N1> rows, cols;
        //    std::vector<nupic::Real ## N2> vals;
        //    self->getNonZerosInBox(row_begin, row_end, col_begin, col_end,
        //        std::back_inserter(rows),
        //        std::back_inserter(cols),
        //        std::back_inserter(vals));
        //    PyObject* toReturn = PyList_New(rows.size());
        //    for (nupic::UInt ## N1 i = 0; i != rows.size(); ++i) {
        //        PyObject* tuple = nupic::createTriplet ## N1(rows[i], cols[i], vals[i]);
        //        PyList_SET_ITEM(toReturn, i, tuple);
        //    }
        //    return toReturn;
        //});

        ////PyObject* tolist() const
        //sm.def("tolist", [](const SparseMatrix32_t& sm)
        //{
        //    const nupic::UInt ## N1 nnz = self->nNonZeros();
        //    std::vector<nupic::UInt ## N1> rows(nnz), cols(nnz);
        //    nupic::NumpyVectorT<nupic::Real ## N2> vals(nnz);
        //    self->getAllNonZeros(rows.begin(), cols.begin(), vals.begin());

        //    PyObject* ind_list = PyTuple_New(nnz);
        //    for (nupic::UInt32 i = 0; i != nnz; ++i) {
        //        PyObject* idx = PyTuple_New(2);
        //        PyTuple_SET_ITEM(idx, 0, PyInt_FromLong(rows[i]));
        //        PyTuple_SET_ITEM(idx, 1, PyInt_FromLong(cols[i]));
        //        PyTuple_SET_ITEM(ind_list, i, idx);
        //    }
        //    PyObject* toReturn = PyTuple_New(2);
        //    PyTuple_SET_ITEM(toReturn, 0, ind_list);
        //    PyTuple_SET_ITEM(toReturn, 1, vals.forPython());
        //    return toReturn;
        //});

        ////void setSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 j_begin, const SparseMatrix ## N2& other)
        //sm.def("setSlice", [](SparseMatrix32_t& sm)
        //{
        //    self->setSlice(i_begin, j_begin, other);
        //});

        ////void setSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 j_begin, PyObject* py_other)
        //sm.def("setSlice", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> other(py_other);
        //    self->setSlice(i_begin, j_begin, other);
        //});

        ////SparseMatrix ## N2 getSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 i_end, nupic::UInt ## N1 j_begin, nupic::UInt ## N1 j_end) const
        //sm.def("getSlice", [](const SparseMatrix32_t& sm)
        //{
        //    SparseMatrix ## N2 other(i_end - i_begin, j_end - j_begin);
        //    self->getSlice(i_begin, i_end, j_begin, j_end, other);
        //    return other;
        //});

        ////SparseMatrix ## N2 getSlice2(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 i_end, nupic::UInt ## N1 j_begin, nupic::UInt ## N1 j_end) const
        //sm.def("getSlice2", [](const SparseMatrix32_t& sm)
        //{
        //    SparseMatrix ## N2 other(i_end - i_begin, j_end - j_begin);
        //    self->getSlice2(i_begin, i_end, j_begin, j_end, other);
        //    return other;
        //});

        ////inline void setRowsToZero(PyObject* py_rows)
        //sm.def("setRowsToZero", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> rows(py_rows);
        //    self->setRowsToZero(rows.begin(), rows.end());
        //});

        ////inline void setColsToZero(PyObject* py_cols)
        //sm.def("setColsToZero", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> cols(py_cols);
        //    self->setColsToZero(cols.begin(), cols.end());
        //});

        ////inline void setDiagonal(PyObject* py_v)
        //sm.def("setDiagonal", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> v(py_v);
        //    self->setDiagonal(v.begin());
        //});

        ////void incrementOnOuterWNZ(PyObject* py_i, PyObject* py_j, nupic::Real ## N2 delta = 1)
        //sm.def("incrementOnOuterWNZ", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    self->incrementOnOuterWNZ(i.begin(), i.end(), j.begin(), j.end(), delta);
        //}, "", py::arg(""));

        ////void incrementOnOuterWNZWThreshold(PyObject* py_i, PyObject* py_j, nupic::Real ## N2 threshold, nupic::Real ## N2 delta = 1)
        //sm.def("incrementOnOuterWNZWThreshold", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> i(py_i), j(py_j);
        //    self->incrementOnOuterWNZWThreshold(i.begin(), i.end(), j.begin(), j.end(),
        //        threshold, delta);
        //}, "", py::arg(""));

        ////void _incrementNonZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 delta)
        //sm.def("incrementNonZerosOnOuter", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    self->incrementNonZerosOnOuter(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        delta);
        //});

        ////void _incrementNonZerosOnRowsExcludingCols(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 delta)
        //sm.def("incrementNonZerosOnRowsExcludingCols", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    self->incrementNonZerosOnRowsExcludingCols(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        delta);
        //});

        ////void _setZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 value)
        //sm.def("setZerosOnOuter", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    self->setZerosOnOuter(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        value);
        //});

        ////void _setRandomZerosOnOuter_singleCount(PyObject* py_rows, PyObject* py_cols, nupic::Int ## N1 numNewNonZeros, nupic::Real ## N2 value, nupic::Random& rng)
        //sm.def("setRandomZerosOnOuter", [](SparseMatrix32_t& sm)
        //{
        //    if isinstance(numNewNonZeros, numbers.Number) :
        //        self._setRandomZerosOnOuter_singleCount(
        //            numpy.asarray(rows, dtype = "uint32"),
        //            numpy.asarray(cols, dtype = "uint32"),
        //            numNewNonZeros,
        //            value,
        //            rng)
        //    else:
        //    self._setRandomZerosOnOuter_multipleCounts(
        //        numpy.asarray(rows, dtype = "uint32"),
        //        numpy.asarray(cols, dtype = "uint32"),
        //        numpy.asarray(numNewNonZeros, dtype = "int32"),
        //        value,
        //        rng)

        //        // _setRandomZerosOnOuter_singleCount
        //        nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    self->setRandomZerosOnOuter(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        numNewNonZeros,
        //        value, rng);

        //    //_setRandomZerosOnOuter_multipleCounts
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);
        //    nupic::NumpyVectorWeakRefT<nupic::Int32>
        //        newNonZeroCounts(py_newNonZeroCounts);

        //    self->setRandomZerosOnOuter(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        newNonZeroCounts.begin(),
        //        newNonZeroCounts.end(),
        //        value, rng);


        //});

        ////void _increaseRowNonZeroCountsOnOuterTo(PyObject* py_rows, PyObject* py_cols, nupic::Int ## N1 numDesiredNonZeros, nupic::Real ## N2 initialValue, nupic::Random& rng)
        //sm.def("increaseRowNonZeroCountsOnOuterTo", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    self->increaseRowNonZeroCountsOnOuterTo(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        numDesiredNonZeros, initialValue,
        //        rng);
        //});

        ////void _clipRowsBelowAndAbove(PyObject* py_rows, nupic::Real ## N2 a, nupic::Real ## N2 b)
        //sm.def("clipRowsBelowAndAbove", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);

        //    self->clipRowsBelowAndAbove(rows.begin(), rows.end(),
        //        a, b);
        //});

        ////PyObject* _nNonZerosPerRow_allRows() const
        //sm.def("_nNonZerosPerRow_allRows", [](const SparseMatrix32_t& sm)
        //{
        //    if rows is None :
        //    return self._nNonZerosPerRow_allRows()
        //    else:
        //    return self._nNonZerosPerRow(numpy.asarray(rows, dtype = "uint32"))

        //    // _nNonZerosPerRow_allRows
        //        nupic::NumpyVectorT<nupic::UInt ## N1> nnzpr(self->nRows());
        //    self->nNonZerosPerRow(nnzpr.begin());
        //    return nnzpr.forPython();

        //    // _nNonZerosPerRow
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);

        //    nupic::NumpyVectorT<nupic::UInt ## N1> out(rows.size());
        //    self->nNonZerosPerRow(rows.begin(), rows.end(), out.begin());

        //    return out.forPython();
        //});


        ////PyObject* _nNonZerosPerRowOnCols(PyObject* py_rows, PyObject* py_cols)
        //sm.def("nNonZerosPerRowOnCols", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
        //    nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);

        //    nupic::NumpyVectorT<nupic::UInt ## N1> out(rows.size());
        //    self->nNonZerosPerRowOnCols(rows.begin(), rows.end(),
        //        cols.begin(), cols.end(),
        //        out.begin());

        //    return out.forPython();
        //});

        ////PyObject* nNonZerosPerCol() const
        //sm.def("nNonZerosPerCol", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> nnzpc(self->nCols());
        //    self->nNonZerosPerCol(nnzpc.begin());
        //    return nnzpc.forPython();
        //});

        ////PyObject* rowBandwidths() const
        //sm.def("rowBandwidths", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> nnzpc(self->nRows());
        //    self->rowBandwidths(nnzpc.begin());
        //    return nnzpc.forPython();
        //});

        ////PyObject* colBandwidths() const
        //sm.def("colBandwidths", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> nnzpc(self->nCols());
        //    self->colBandwidths(nnzpc.begin());
        //    return nnzpc.forPython();
        //});

        ////SparseMatrix ## N1 nNonZerosPerBox(PyObject* box_i, PyObject* box_j) const
        //sm.def("nNonZerosPerBox", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> bounds_i(box_i);
        //    nupic::NumpyVectorT<nupic::UInt ## N1> bounds_j(box_j);
        //    SparseMatrix ## N1 result(bounds_i.size(), bounds_j.size());
        //    self->nNonZerosPerBox(bounds_i.begin(), bounds_i.end(),
        //        bounds_j.begin(), bounds_j.end(),
        //        result);
        //    return result;
        //});

        ////PyObject* max() const
        //sm.def("max", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 max_row, max_col;
        //    nupic::Real ## N2 max_val;
        //    self->max(max_row, max_col, max_val);
        //    return nupic::createTriplet ## N1(max_row, max_col, max_val);
        //});

        ////PyObject* min() const
        //sm.def("min", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 min_row, min_col;
        //    nupic::Real ## N2 min_val;
        //    self->min(min_row, min_col, min_val);
        //    return nupic::createTriplet ## N1(min_row, min_col, min_val);
        //});

        ////PyObject* rowMin(nupic::UInt ## N1 row_index) const
        //sm.def("rowMin", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 idx;
        //    nupic::Real ## N2 min_val;
        //    self->rowMin(row_index, idx, min_val);
        //    return nupic::createPair ## N1(idx, min_val);
        //});

        ////PyObject* rowMax(nupic::UInt ## N1 row_index) const
        //sm.def("rowMax", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 idx;
        //    nupic::Real ## N2 max_val;
        //    self->rowMax(row_index, idx, max_val);
        //    return nupic::createPair ## N1(idx, max_val);
        //});

        ////PyObject* colMin(nupic::UInt ## N1 col_index) const
        //sm.def("colMin", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 idx;
        //    nupic::Real ## N2 min_val;
        //    self->colMin(col_index, idx, min_val);
        //    return nupic::createPair ## N1(idx, min_val);
        //});

        ////PyObject* colMax(nupic::UInt ## N1 row_index) const
        //sm.def("colMax", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 idx;
        //    nupic::Real ## N2 max_val;
        //    self->colMax(row_index, idx, max_val);
        //    return nupic::createPair ## N1(idx, max_val);
        //});

        ////PyObject* rowMax() const
        //sm.def("rowMax", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 n = self->nRows();
        //    std::vector<nupic::UInt ## N1> ind(n);
        //    nupic::NumpyVectorT<nupic::Real ## N2> val(n);
        //    self->rowMax(ind.begin(), val.begin());
        //    PyObject *toReturn = PyTuple_New(2);
        //    PyTuple_SET_ITEM(toReturn, 0, nupic::PyInt ## N1 ## Vector(ind.begin(), ind.end()));
        //    PyTuple_SET_ITEM(toReturn, 1, val.forPython());
        //    return toReturn;
        //});

        ////PyObject* rowMin() const
        //sm.def("rowMin", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 n = self->nRows();
        //    std::vector<nupic::UInt ## N1> ind(n);
        //    nupic::NumpyVectorT<nupic::Real ## N2> val(n);
        //    self->rowMin(ind.begin(), val.begin());
        //    PyObject *toReturn = PyTuple_New(2);
        //    PyTuple_SET_ITEM(toReturn, 0, nupic::PyInt ## N1 ## Vector(ind.begin(), ind.end()));
        //    PyTuple_SET_ITEM(toReturn, 1, val.forPython());
        //    return toReturn;
        //});

        ////PyObject* colMax() const
        //sm.def("colMax", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 n = self->nCols();
        //    std::vector<nupic::UInt ## N1> ind(n);
        //    nupic::NumpyVectorT<nupic::Real ## N2> val(n);
        //    self->colMax(ind.begin(), val.begin());
        //    PyObject *toReturn = PyTuple_New(2);
        //    PyTuple_SET_ITEM(toReturn, 0, nupic::PyInt ## N1 ## Vector(ind.begin(), ind.end()));
        //    PyTuple_SET_ITEM(toReturn, 1, val.forPython());
        //    return toReturn;
        //});

        ////PyObject* colMin() const
        //sm.def("colMin", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 n = self->nCols();
        //    std::vector<nupic::UInt ## N1> ind(n);
        //    nupic::NumpyVectorT<nupic::Real ## N2> val(n);
        //    self->colMin(ind.begin(), val.begin());
        //    PyObject *toReturn = PyTuple_New(2);
        //    PyTuple_SET_ITEM(toReturn, 0, nupic::PyInt ## N1 ## Vector(ind.begin(), ind.end()));
        //    PyTuple_SET_ITEM(toReturn, 1, val.forPython());
        //    return toReturn;
        //});

        ////PyObject* boxMin(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col) const
        //sm.def("boxMin", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 min_row, min_col;
        //    nupic::Real ## N2 min_val;
        //    self->boxMin(begin_row, end_row, begin_col, end_col, min_row, min_col, min_val);
        //    return nupic::createTriplet ## N1(min_row, min_col, min_val);
        //});

        ////PyObject* boxMax(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col) const
        //sm.def("boxMax", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::UInt ## N1 max_row, max_col;
        //    nupic::Real ## N2 max_val;
        //    self->boxMax(begin_row, end_row, begin_col, end_col, max_row, max_col, max_val);
        //    return nupic::createTriplet ## N1(max_row, max_col, max_val);
        //});

        ////PyObject* whereEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const
        //sm.def("whereEqual", [](const SparseMatrix32_t& sm)
        //{
        //    std::vector<nupic::UInt ## N1> rows, cols;
        //    self->whereEqual(begin_row, end_row, begin_col, end_col, value,
        //        std::back_inserter(rows), std::back_inserter(cols));

        //    PyObject* toReturn = PyTuple_New(rows.size());

        //    for (size_t i = 0; i != rows.size(); ++i) {
        //        PyObject* p = PyTuple_New(2);
        //        PyTuple_SET_ITEM(p, 0, PyInt_FromLong(rows[i]));
        //        PyTuple_SET_ITEM(p, 1, PyInt_FromLong(cols[i]));
        //        PyTuple_SET_ITEM(toReturn, i, p);
        //    }

        //    return toReturn;
        //});

        ////PyObject* whereGreater(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const
        //sm.def("whereGreater", [](const SparseMatrix32_t& sm)
        //{
        //    std::vector<nupic::UInt ## N1> rows, cols;
        //    self->whereGreater(begin_row, end_row, begin_col, end_col, value,
        //        std::back_inserter(rows), std::back_inserter(cols));

        //    int dims[] = { static_cast<int>(rows.size()), 2 };
        //    nupic::NumpyMatrixT<nupic::UInt ## N1> toReturn(dims);
        //    for (size_t i = 0; i != rows.size(); ++i) {
        //        toReturn.set(i, 0, rows[i]);
        //        toReturn.set(i, 1, cols[i]);
        //    }
        //    return toReturn.forPython();
        //});

        ////PyObject* whereGreaterEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const
        //sm.def("whereGreaterEqual", [](const SparseMatrix32_t& sm)
        //{
        //    std::vector<nupic::UInt ## N1> rows, cols;
        //    self->whereGreaterEqual(begin_row, end_row, begin_col, end_col, value,
        //        std::back_inserter(rows), std::back_inserter(cols));


        //    int dims[] = { static_cast<int>(rows.size()), 2 };
        //    nupic::NumpyMatrixT<nupic::UInt ## N1> toReturn(dims);
        //    for (size_t i = 0; i != rows.size(); ++i) {
        //        toReturn.set(i, 0, rows[i]);
        //        toReturn.set(i, 1, cols[i]);
        //    }
        //    return toReturn.forPython();
        //});

        ////nupic::UInt32 countWhereGreaterOrEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const
        //sm.def("countWhereGreaterOrEqual", [](const SparseMatrix32_t& sm)
        //{
        //    std::vector<nupic::UInt ## N1> rows, cols;
        //    return self->countWhereGreaterEqual(begin_row, end_row, begin_col, end_col, value);
        //});

        ////void permuteRows(PyObject* py_permutation)
        //sm.def("permuteRows", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> p(py_permutation);
        //    self->permuteRows(p.begin());
        //});

        ////void permuteCols(PyObject* py_permutation)
        //sm.def("permuteCols", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> p(py_permutation);
        //    self->permuteCols(p.begin());
        //});

        ////PyObject* rowSums() const
        //sm.def("rowSums", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nRows());
        //    self->rowSums(m.begin());
        //    return m.forPython();
        //});

        ////PyObject* colSums() const
        //sm.def("colSums", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nCols());
        //    self->colSums(m.begin());
        //    return m.forPython();
        //});

        ////PyObject* addRows(PyObject* whichRows) const
        //sm.def("addRows", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> indicator(whichRows);
        //    nupic::NumpyVectorT<nupic::Real ## N2> res(self->nCols());
        //    self->addRows(indicator.begin(), indicator.end(), res.begin(), res.end());
        //    return res.forPython();
        //});

        ////PyObject* addListOfRows(PyObject* py_whichRows) const
        //sm.def("addListOfRows", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N1> whichRows(py_whichRows);
        //    nupic::NumpyVectorT<nupic::Real ## N2> res(self->nCols());
        //    self->addListOfRows(whichRows.begin(), whichRows.end(), res.begin(), res.end());
        //    return res.forPython();
        //});

        ////PyObject* rowProds() const
        //sm.def("rowProds", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nRows());
        //    self->rowProds(m.begin());
        //    return m.forPython();
        //});

        ////PyObject* colProds() const
        //sm.def("colProds", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nCols());
        //    self->colProds(m.begin());
        //    return m.forPython();
        //});

        ////PyObject* logRowSums() const
        //sm.def("logRowSums", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nRows());
        //    self->logRowSums(m.begin(), m.end());
        //    return m.forPython();
        //});

        ////PyObject* logColSums() const
        //sm.def("logColSums", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> m(self->nCols());
        //    self->logColSums(m.begin(), m.end());
        //    return m.forPython();
        //});

        ////void scaleRows(PyObject* py_s)
        //sm.def("scaleRows", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> s(py_s);
        //    self->scaleRows(s.begin());
        //});

        ////void scaleCols(PyObject* py_s)
        //sm.def("scaleCols", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> s(py_s);
        //    self->scaleCols(s.begin());
        //});

        ////void normalizeBlockByRows(PyObject* py_inds, nupic::Real ## N2 val = -1.0, nupic::Real ## N2 eps_n = 1e-6)
        //sm.def("normalizeBlockByRows", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N2> inds(py_inds);
        //    self->normalizeBlockByRows(inds.begin(), inds.end(), val, eps_n);
        //}, "", py::arg(""));

        ////void normalizeBlockByRows_binary(PyObject* py_inds, nupic::Real ## N2 val = -1.0, nupic::Real ## N2 eps_n = 1e-6)
        //sm.def("normalizeBlockByRows_binary", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N2> inds(py_inds);
        //    self->normalizeBlockByRows_binary(inds.begin(), inds.end(), val, eps_n);
        //}, "", py::arg(""));

        ////void axby(nupic::UInt ## N1 row, nupic::Real ## N2 a, nupic::Real ## N2 b, PyObject *xIn)
        //sm.def("axby", [](SparseMatrix32_t& sm)
        //{
        //    PyArrayObject* x = (PyArrayObject*)xIn;
        //    nupic::Real ## N2* x_begin = (nupic::Real ## N2*)(PyArray_DATA(x));
        //    self->axby(row, a, b, x_begin);
        //});

        ////void axby(nupic::Real ## N2 a, nupic::Real ## N2 b, PyObject *xIn)
        //sm.def("axby", [](SparseMatrix32_t& sm)
        //{
        //    PyArrayObject* x = (PyArrayObject*)xIn;
        //    nupic::Real ## N2* x_begin = (nupic::Real ## N2*)(PyArray_DATA(x));
        //    self->axby(a, b, x_begin);
        //});

        ////nupic::Real ## N2 rightVecProd(nupic::UInt ## N1 row, PyObject *xIn) const
        //sm.def("rightVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    return self->rightVecProd(row, x.begin());
        //}, "Computes the dot product of the given row with the given vector.");

        ////inline PyObject* rightVecProd(PyObject *xIn) const
        //sm.def("rightVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    nupic::NumpyVectorT<nupic::Real ## N2> y(self->nRows());
        //    self->rightVecProd(x.begin(), y.begin());
        //    return y.forPython();
        //}, "Regular matrix vector multiplication, with allocation of the result.");

        ////inline void rightVecProd_fast(PyObject *xIn, PyObject *yOut) const
        //sm.def("rightVecProd_fast", [](const SparseMatrix32_t& sm)
        //{
        //    PyArrayObject* x = (PyArrayObject*)xIn;
        //    nupic::Real ## N2* x_begin = (nupic::Real ## N2*)(PyArray_DATA(x));
        //    PyArrayObject* y = (PyArrayObject*)yOut;
        //    nupic::Real ## N2* y_begin = (nupic::Real ## N2*)(PyArray_DATA(y));
        //    self->rightVecProd(x_begin, y_begin);
        //}, "Regular matrix vector multiplication, with allocation of the result. Fast because doesn't go through NumpyVectorT and doesn't allocate memory.");

        ////PyObject* rightVecProd(PyObject* pyRows, PyObject *xIn) const
        //sm.def("rightVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    nupic::NumpyVectorT<nupic::UInt ## N1> rows(pyRows);
        //    nupic::NumpyVectorT<nupic::Real ## N2> y(rows.size());
        //    self->rightVecProd(rows.begin(), rows.end(), x.begin(), y.begin());
        //    return y.forPython();
        //}, "Matrix vector product on the right side, only for some rows.");

        ////SparseMatrix ## N2 blockRightVecProd(nupic::UInt ## N1 block_size, PyObject* xIn) const
        //sm.def("blockRightVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    SparseMatrix ## N2 result;
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->blockRightVecProd(block_size, x.begin(), result);
        //    return result;
        //});

        ////nupic::Real ## N2 leftVecProd(nupic::UInt ## N1 col, PyObject *xIn) const
        //sm.def("leftVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    return self->leftVecProd(col, x.begin());
        //}, "Dot product of column col and vector xIn.");

        ////PyObject* leftVecProd(PyObject *xIn) const
        //sm.def("leftVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    nupic::NumpyVectorT<nupic::Real ## N2> y(self->nCols());
        //    self->leftVecProd(x.begin(), y.begin());
        //    return y.forPython();
        //}, "Vector matrix product on the left, i.e. dot product of xIn and each column of the matrix.");

        ////PyObject* leftVecProd(PyObject* pyCols, PyObject *xIn) const
        //sm.def("leftVecProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N2> cols(pyCols);
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn), y(cols.size());
        //    self->leftVecProd(cols.begin(), cols.end(), x.begin(), y.begin());
        //    return y.forPython();
        //});

        ////PyObject* leftVecProd_binary(PyObject* pyCols, PyObject *xIn) const
        //sm.def("leftVecProd_binary", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::UInt ## N2> cols(pyCols);
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn), y(cols.size());
        //    self->leftVecProd_binary(cols.begin(), cols.end(), x.begin(), y.begin());
        //    return y.forPython();
        //}, "Binary search for the columns.");

        ////PyObject* rightDenseMatProd(PyObject* mIn) const
        //sm.def("rightDenseMatProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> m(mIn);
        //    int nRowsCols[2];
        //    nRowsCols[0] = self->nRows();
        //    nRowsCols[1] = m.nCols();
        //    nupic::NumpyMatrixT<nupic::Real ## N2> r(nRowsCols);
        //    self->rightDenseMatProd(m, r);
        //    return r.forPython();
        //});

        ////PyObject* rightDenseMatProdAtNZ(PyObject* mIn) const
        //sm.def("rightDenseMatProdAtNZ", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> m(mIn);
        //    int nRowsCols[2];
        //    nRowsCols[0] = self->nRows();
        //    nRowsCols[1] = m.nCols();
        //    nupic::NumpyMatrixT<nupic::Real ## N2> r(nRowsCols);
        //    self->rightDenseMatProdAtNZ(m, r);
        //    return r.forPython();
        //});

        ////PyObject* denseMatExtract(PyObject* mIn) const
        //sm.def("denseMatExtract", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> m(mIn);
        //    int nRowsCols[2];
        //    nRowsCols[0] = self->nRows();
        //    nRowsCols[1] = m.nCols();
        //    nupic::NumpyMatrixT<nupic::Real ## N2> r(nRowsCols);
        //    self->denseMatExtract(m, r);
        //    return r.forPython();
        //});

        ////PyObject* leftDenseMatProd(PyObject* mIn) const
        //sm.def("leftDenseMatProd", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> m(mIn);
        //    int nRowsCols[2];
        //    nRowsCols[0] = m.nRows();
        //    nRowsCols[1] = self->nCols();
        //    nupic::NumpyMatrixT<nupic::Real ## N2> r(nRowsCols);
        //    for (int i = 0; i != m.nRows(); ++i)
        //        self->leftVecProd(m.begin(i), r.begin(i));
        //    return r.forPython();
        //});

        ////void elementRowAdd(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementRowAdd", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementRowAdd(i, x.begin());
        //});

        ////void elementRowSubtract(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementRowSubtract", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementRowSubtract(i, x.begin());
        //});

        ////void elementRowMultiply(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementRowMultiply", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementRowMultiply(i, x.begin());
        //});

        ////void elementRowDivide(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementRowDivide", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementRowDivide(i, x.begin());
        //});

        ////void elementColAdd(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementColAdd", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementColAdd(i, x.begin());
        //});

        ////void elementColSubtract(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementColSubtract", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementColSubtract(i, x.begin());
        //});

        ////void elementColMultiply(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementColMultiply", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementColMultiply(i, x.begin());
        //});

        ////void elementColDivide(nupic::UInt ## N1 i, PyObject* xIn)
        //sm.def("elementColDivide", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn);
        //    self->elementColDivide(i, x.begin());
        //});

        ////void elementMultiply(PyObject* mIn)
        //sm.def("elementMultiply", [](SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyMatrixT<nupic::Real ## N2> m(mIn);
        //    self->elementMultiply(m.begin(0));
        //});

        //////--------------------------------------------------------------------------------
        ////// AtNZ operations, i.e. considering the sparse matrix as a 0/1 sparse matrix.
        //////--------------------------------------------------------------------------------

        ////PyObject* rightVecProdAtNZ(PyObject* xIn) const
        //sm.def("rightVecProdAtNZ", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn), y(self->nRows());
        //    self->rightVecProdAtNZ(x.begin(), y.begin());
        //    return y.forPython();
        //});

        ////PyObject* leftVecProdAtNZ(PyObject* xIn) const
        //sm.def("leftVecProdAtNZ", [](const SparseMatrix32_t& sm)
        //{
        //    nupic::NumpyVectorT<nupic::Real ## N2> x(xIn), y(self->nCols());
        //    self->leftVecProdAtNZ(x.begin(), y.begin());
        //    return y.forPython();
        //});

        //// rightVecSumAtNZ
        //sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t self, py::array_t<nupic::Real32>& denseArray)
        //{
        //    py::array_t<nupic::Real32> out(self.nRows());
        //    self.rightVecSumAtNZ(get_it(denseArray), get_it(out));

        //    return out;
        //});


        //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////


        //inline void _rightVecSumAtNZSparse(PyObject* py_sparseBinaryArray, PyObject* py_out) const

        //inline void _rightVecSumAtNZGtThreshold(PyObject* py_denseArray, nupic::Real ## N2 threshold, PyObject* py_out) const

        //inline void _rightVecSumAtNZGtThresholdSparse(PyObject* py_sparseBinaryArray, nupic::Real ## N2 threshold, PyObject* py_out) const


        //inline void _rightVecSumAtNZGteThreshold(PyObject* py_denseArray, nupic::Real ## N2 threshold, PyObject* py_out) const

        //inline void _rightVecSumAtNZGteThresholdSparse(PyObject* py_sparseBinaryArray, nupic::Real ## N2 threshold, PyObject* py_out) const

        //// Regular matrix vector multiplication on the left side, assuming that the
        //// values of the non-zeros are all 1, so that we can save actually computing
        //// the multiplications. Allocates the result.
        //inline PyObject* leftVecSumAtNZ(PyObject* xIn) const

        //// Regular matrix vector multiplication on the left, without allocation
        //// of the result, assuming that the values of the non-zeros are always 1 in the
        //// sparse matrix, so that we can save computing multiplications explicitly.
        //// Also fast because doesn't go through NumpyVectorT and doesn't allocate
        //// memory.
        //inline void leftVecSumAtNZ_fast(PyObject *xIn, PyObject *yOut) const

        //PyObject* rightDenseMatProdAtNZ(PyObject* mIn) const

        //PyObject* leftDenseMatProdAtNZ(PyObject* mIn) const

        //PyObject* rightDenseMatSumAtNZ(PyObject* mIn) const

        //PyObject* leftDenseMatSumAtNZ(PyObject* mIn) const

        //PyObject* rightDenseMatMaxAtNZ(PyObject* mIn) const

        //PyObject* leftDenseMatMaxAtNZ(PyObject* mIn) const

        //PyObject* vecArgMaxAtNZ(PyObject *xIn)

        //PyObject* vecMaxAtNZ(PyObject *xIn)

        //PyObject* rowVecProd(PyObject* xIn, nupic::Real ## N2 lb = nupic::Epsilon) const

        //PyObject* vecMaxProd(PyObject *xIn)

        //PyObject* vecArgMaxProd(PyObject *xIn)

        //PyObject* getNonZerosSorted(nupic::Int n = -1, bool ascending_values = true) const

        //PyObject* threshold(nupic::Real ## N2 threshold, bool getCuts = false)

        //PyObject* toPyString() const

        //bool fromPyString(PyObject *s)

        //bool __eq__(const SparseMatrix ## N2& other) const
        //bool __ne__(const SparseMatrix ## N2& other) const



        //////////////////////

        sm.def("initializeWithFixedNNZR", [](SparseMatrix32_t self, nupic::UInt32 nnzr, nupic::Real32 v, nupic::UInt32 mode, nupic::UInt32 seed)
        {
            self.initializeWithFixedNNZR(nnzr, v, mode, seed);
        }, "Initialize a sparse matrix with a fixed number of non-zeros on each row."
            , py::arg("nnzr"), py::arg("v") = 1.0, py::arg("mode") = 0, py::arg("seed") = 42);


    }

} // namespace nupix_ext
