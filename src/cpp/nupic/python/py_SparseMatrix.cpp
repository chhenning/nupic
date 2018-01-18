
#include <fstream>

#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/math/SparseMatrix.hpp>

#include "Matrix.hpp"
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

        sm.def(py::init([](const std::string& str)
        {
            SparseMatrix32_t s;

            std::stringstream ss(str);
            s.fromCSR(ss);

            return s;
        }));
            

        // constructor from numpy array
        sm.def(py::init(
            [](py::array_t<nupic::UInt32>& a)
        {
            if (a.ndim() != 2) { throw std::runtime_error("Number of dimensions must be two."); }

            SparseMatrix32_t s(a.shape(0), a.shape(1), get_it(a));

            return s;
        }));

        sm.def(py::init(
            [](py::array_t<nupic::Real32>& a)
        {
            if (a.ndim() != 2) { throw std::runtime_error("Number of dimensions must be two."); }

            SparseMatrix32_t s(a.shape(0), a.shape(1), get_it(a));

            return s;
        }));

        sm.def("__add", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.add(val); });
        sm.def("__multiply", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.multiply(val); });
        sm.def("__subtract", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.subtract(val); });
        sm.def("__divide", [](SparseMatrix32_t& sm, nupic::Real32 val) { sm.divide(val); });
        
        sm.def("__str__", [](SparseMatrix32_t& sm) 
        {
            auto out = py::array_t<nupic::Real32>({ sm.nRows(), sm.nCols() });

            sm.toDense(get_it(out));

            return out.attr("__str__")();
        });


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
            sm.toDense(get_it(out));

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


        //PyObject* getCol(nupic::UInt32 col) const
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

        //PyObject* rowNonZeros(nupic::UInt32 row) const
        sm.def("rowNonZeros", [](const SparseMatrix32_t& sm, nupic::UInt32 row)
        {
            const auto n = sm.nNonZerosOnRow(row);
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(sm.nRows());
            sm.getRowToSparse(row, get_it(ind), get_it(val));

            return py::make_tuple(ind, val);
        });

        //PyObject* rowNonZeroIndices(nupic::UInt32 row) const
        sm.def("rowNonZeroIndices", [](const SparseMatrix32_t& sm, nupic::UInt32 row)
        {
            const auto n = sm.nNonZerosOnRow(row);
            py::array_t<nupic::UInt32> ind(n); 
            
            sm.getRowIndicesToSparse(row, get_it(ind));
            
            return ind;
        });

        //PyObject* colNonZeros(nupic::UInt32 col) const
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

        //void setElements(PyObject* py_i, PyObject* py_j, PyObject* py_v)
        sm.def("setElements", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, py::array_t<nupic::Real32>& v)
        {
            sm.setElements(get_it(i), get_end(i), get_it(j), get_it(v));
        });

        //PyObject* getElements(PyObject* py_i, PyObject* py_j) const
        sm.def("getElements", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j)
        {
            py::array_t<nupic::Real32> v(i.size());

            sm.getElements(get_it(i), get_end(i), get_it(j), get_it(v));

            return v;
        });

        //void setOuter(PyObject* py_i, PyObject* py_j, PyObject* py_v)
        sm.def("setOuter", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, py::array_t<nupic::Real32>& v)
        {
            throw std::runtime_error("Not implemented.");

            // setOuter cannot deal with py::array_t
            //sm.setOuter(get_it(i), get_end(i), get_it(j), get_end(j), v);
        
        }, "Sets on the outer product of the passed ranges.");

        //SparseMatrix32 getOuter(PyObject* py_i, PyObject* py_j) const
        sm.def("getOuter", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j)
        {
            SparseMatrix32_t v(i.size(), j.size());

            sm.getOuter(get_it(i), get_end(i), get_it(j), get_end(j), v);

            return v;
        }, "Get on the outer products of the passed ranges.");

        //PyObject* getAllNonZeros(bool three_lists = false) const
        sm.def("getAllNonZeros", [](const SparseMatrix32_t& sm, bool three_lists)
        {
            const auto nnz = sm.nNonZeros();
            
            py::array_t<nupic::UInt32> rows(nnz), cols(nnz);
            py::array_t<nupic::Real32> vals(nnz);

            sm.getAllNonZeros(get_it(rows), get_it(cols), get_it(vals));

            if (!three_lists)
            {
                // Return one list of triples
                py::tuple toReturn(nnz);

                for (nupic::UInt32 i = 0; i != nnz; ++i)
                {
                    toReturn[i] = py::make_tuple(rows.data(i), cols.data(i), vals.data(i));
                }
                
                return toReturn;
            }
            else
            {
                py::tuple toReturn(3);

                // Return three lists
                toReturn[0] = rows;
                toReturn[1] = cols;
                toReturn[2] = vals;

                return toReturn;
            }
        }, "Returns the positions and values of all the non-zeros stored in this matrix. The result can be either three lists ((i), (j), (v)) or one list of triples (i,j,v)."
        , py::arg("three_lists") = false);

        //void setAllNonZeros(nupic::UInt32 nrows, nupic::UInt32 ncols, PyObject* py_i, PyObject* py_j, PyObject* py_v, bool sorted = true)
        sm.def("setAllNonZeros", [](SparseMatrix32_t& sm, nupic::UInt32 nrows, nupic::UInt32 ncols
            , py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, py::array_t<nupic::Real32>& v
            , bool sorted)
        {
            sm.setAllNonZeros(nrows, ncols,
                get_it(i), get_end(i),
                get_it(j), get_end(j),
                get_it(v), get_end(v),
                sorted);
        }, "", py::arg("nrows"), py::arg("ncols"), py::arg("i"), py::arg("j"), py::arg("v"), py::arg("sorted") = true);

        //PyObject* getNonZerosInBox(nupic::UInt32 row_begin, nupic::UInt32 row_end, nupic::UInt32 col_begin, nupic::UInt32 col_end) const
        sm.def("getNonZerosInBox", [](const SparseMatrix32_t& sm, nupic::UInt32 row_begin, nupic::UInt32 row_end
            , nupic::UInt32 col_begin, nupic::UInt32 col_end)
        {
            std::vector<nupic::UInt32> rows, cols;
            std::vector<nupic::Real32> vals;

            sm.getNonZerosInBox(row_begin, row_end, col_begin, col_end,
                std::back_inserter(rows),
                std::back_inserter(cols),
                std::back_inserter(vals));

            py::tuple toReturn(rows.size());

            for (nupic::UInt32 i = 0; i != rows.size(); ++i)
            {
                toReturn[i] = py::make_tuple(rows[i], cols[i], vals[i]);
            }

            return toReturn;
        });

        //PyObject* tolist() const
        sm.def("tolist", [](const SparseMatrix32_t& sm)
        {
            const auto nnz = sm.nNonZeros();
            std::vector<nupic::UInt32> rows(nnz), cols(nnz);
            py::array_t<nupic::Real32> vals(nnz);
            sm.getAllNonZeros(rows.begin(), cols.begin(), get_it(vals));

            py::tuple toReturn(rows.size());

            py::tuple ind_list(nnz);
            
            for (nupic::UInt32 i = 0; i != nnz; ++i)
            {
                ind_list[i] = py::make_tuple(rows[i], cols[i]);
            }
            
            return py::make_tuple(ind_list, vals);
        });

        //void setSlice(nupic::UInt32 i_begin, nupic::UInt32 j_begin, const SparseMatrix32& other)
        sm.def("setSlice", [](SparseMatrix32_t& sm, nupic::UInt32 i_begin, nupic::UInt32 j_begin, const SparseMatrix32_t& other)
        {
            sm.setSlice(i_begin, j_begin, other);
        });

        //void setSlice(nupic::UInt32 i_begin, nupic::UInt32 j_begin, PyObject* py_other)
        sm.def("setSlice", [](SparseMatrix32_t& sm, nupic::UInt32 i_begin, nupic::UInt32 j_begin, py::array_t<nupic::Real32>& other)
        {
            throw std::runtime_error("Not implemented.");

            // setSlice cannot deal with py::array_t
            //sm.setSlice(i_begin, j_begin, other);
        });

        //SparseMatrix32 getSlice(nupic::UInt32 i_begin, nupic::UInt32 i_end, nupic::UInt32 j_begin, nupic::UInt32 j_end) const
        sm.def("getSlice", [](const SparseMatrix32_t& sm, nupic::UInt32 i_begin, nupic::UInt32 i_end, nupic::UInt32 j_begin, nupic::UInt32 j_end)
        {
            SparseMatrix32_t other(i_end - i_begin, j_end - j_begin);

            sm.getSlice(i_begin, i_end, j_begin, j_end, other);

            return other;
        });

        //SparseMatrix32 getSlice2(nupic::UInt32 i_begin, nupic::UInt32 i_end, nupic::UInt32 j_begin, nupic::UInt32 j_end) const
        sm.def("getSlice2", [](const SparseMatrix32_t& sm, nupic::UInt32 i_begin, nupic::UInt32 i_end, nupic::UInt32 j_begin, nupic::UInt32 j_end)
        {
            SparseMatrix32_t other(i_end - i_begin, j_end - j_begin);

            sm.getSlice2(i_begin, i_end, j_begin, j_end, other);

            return other;
        });

        //inline void setRowsToZero(PyObject* py_rows)
        sm.def("setRowsToZero", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows)
        {
            sm.setRowsToZero(get_it(rows), get_end(rows));
        });

        //inline void setColsToZero(PyObject* py_cols)
        sm.def("setColsToZero", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& cols)
        {
            sm.setColsToZero(get_it(cols), get_end(cols));
        });

        //inline void setDiagonal(PyObject* py_v)
        sm.def("setDiagonal", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& v)
        {
            sm.setDiagonal(get_it(v));
        });

        //void incrementOnOuterWNZ(PyObject* py_i, PyObject* py_j, nupic::Real32 delta = 1)
        sm.def("incrementOnOuterWNZ", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j, nupic::Real32 delta)
        {
            throw std::runtime_error("Not implemented.");

            // incrementOnOuterWNZ cannot deal with py::array_t
            //sm.incrementOnOuterWNZ(i.begin(), i.end(), j.begin(), j.end(), delta);
        }, "", py::arg("i"), py::arg("j"), py::arg("delta") = 1);

        //void incrementOnOuterWNZWThreshold(PyObject* py_i, PyObject* py_j, nupic::Real32 threshold, nupic::Real32 delta = 1)
        sm.def("incrementOnOuterWNZWThreshold", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& i, py::array_t<nupic::UInt32>& j
            , nupic::Real32 threshold, nupic::Real32 delta)
        {
            sm.incrementOnOuterWNZWThreshold(get_it(i), get_end(i), get_it(j), get_end(j), threshold, delta);
        }, "", py::arg("i"), py::arg("j"), py::arg("threshold"), py::arg("delta"));

        //void _incrementNonZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real32 delta)
        sm.def("incrementNonZerosOnOuter", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols, nupic::Real32 delta)
        {
            sm.incrementNonZerosOnOuter(get_it(rows), get_end(rows), get_it(cols), get_end(cols), delta);
        });

        //void _incrementNonZerosOnRowsExcludingCols(PyObject* py_rows, PyObject* py_cols, nupic::Real32 delta)
        sm.def("incrementNonZerosOnRowsExcludingCols", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols, nupic::Real32 delta)
        {
            sm.incrementNonZerosOnRowsExcludingCols(get_it(rows), get_end(rows), get_it(cols), get_end(cols), delta);
        });

        //void _setZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real32 value)
        sm.def("setZerosOnOuter", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols, nupic::Real32 value)
        {
            sm.setZerosOnOuter(get_it(rows), get_end(rows), get_it(cols), get_end(cols), value);
        });

        ////void _setRandomZerosOnOuter_singleCount(PyObject* py_rows, PyObject* py_cols, nupic::Int32 numNewNonZeros, nupic::Real32 value, nupic::Random& rng)
        sm.def("setRandomZerosOnOuter", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols
            , nupic::Int32 numNewNonZeros, nupic::Real32 value, nupic::Random& rng)
        {
            // @todo incorporate python code

            //if isinstance(numNewNonZeros, numbers.Number) :
            //    self._setRandomZerosOnOuter_singleCount(
            //        numpy.asarray(rows, dtype = "uint32"),
            //        numpy.asarray(cols, dtype = "uint32"),
            //        numNewNonZeros,
            //        value,
            //        rng)
            //else:
            //self._setRandomZerosOnOuter_multipleCounts(
            //    numpy.asarray(rows, dtype = "uint32"),
            //    numpy.asarray(cols, dtype = "uint32"),
            //    numpy.asarray(numNewNonZeros, dtype = "int32"),
            //    value,
            //    rng)

            // _setRandomZerosOnOuter_singleCount
            sm.setRandomZerosOnOuter(get_it(rows), get_end(rows), get_it(cols), get_end(cols), numNewNonZeros, value, rng);

            //_setRandomZerosOnOuter_multipleCounts
            //nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);
            //nupic::NumpyVectorWeakRefT<nupic::UInt32> cols(py_cols);
            //nupic::NumpyVectorWeakRefT<nupic::Int32>
            //    newNonZeroCounts(py_newNonZeroCounts);

            //sm.setRandomZerosOnOuter(rows.begin(), rows.end(),
            //    cols.begin(), cols.end(),
            //    newNonZeroCounts.begin(),
            //    newNonZeroCounts.end(),
            //    value, rng);
        });

        //void _increaseRowNonZeroCountsOnOuterTo(PyObject* py_rows, PyObject* py_cols, nupic::Int32 numDesiredNonZeros, nupic::Real32 initialValue, nupic::Random& rng)
        sm.def("increaseRowNonZeroCountsOnOuterTo", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols
            , nupic::Int32 numDesiredNonZeros, nupic::Real32 initialValue, nupic::Random& rng)
        {
            sm.increaseRowNonZeroCountsOnOuterTo(get_it(rows), get_end(rows), get_it(cols), get_end(cols),
                numDesiredNonZeros, initialValue,
                rng);
        });

        //void _clipRowsBelowAndAbove(PyObject* py_rows, nupic::Real32 a, nupic::Real32 b)
        sm.def("clipRowsBelowAndAbove", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, nupic::Real32 a, nupic::Real32 b)
        {
            sm.clipRowsBelowAndAbove(get_it(rows), get_end(rows), a, b);
        });

        //PyObject* _nNonZerosPerRow_allRows() const
        sm.def("_nNonZerosPerRow_allRows", [](const SparseMatrix32_t& sm)
        {
            // @todo incorporate python code
            //if rows is None :
            //return self._nNonZerosPerRow_allRows()
            //else:
            //return self._nNonZerosPerRow(numpy.asarray(rows, dtype = "uint32"))

            // _nNonZerosPerRow_allRows
            py::array_t<nupic::UInt32> nnzpr(sm.nRows());
            
            sm.nNonZerosPerRow(get_it(nnzpr));
            
            return nnzpr;

            // _nNonZerosPerRow
            //nupic::NumpyVectorWeakRefT<nupic::UInt32> rows(py_rows);

            //py::array_t<nupic::UInt32> out(rows.size());
            //sm.nNonZerosPerRow(rows.begin(), rows.end(), out.begin());

            //return out.forPython();
        });


        //PyObject* _nNonZerosPerRowOnCols(PyObject* py_rows, PyObject* py_cols)
        sm.def("nNonZerosPerRowOnCols", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& rows, py::array_t<nupic::UInt32>& cols)
        {
            py::array_t<nupic::UInt32> out(rows.size());

            sm.nNonZerosPerRowOnCols(get_it(rows), get_end(rows), get_it(cols), get_end(cols), get_it(out));

            return out;
        });

        //PyObject* nNonZerosPerCol() const
        sm.def("nNonZerosPerCol", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::UInt32> nnzpc(sm.nCols());

            sm.nNonZerosPerCol(get_it(nnzpc));

            return nnzpc;
        });

        //PyObject* rowBandwidths() const
        sm.def("rowBandwidths", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::UInt32> nnzpc(sm.nRows());
            
            sm.rowBandwidths(get_it(nnzpc));
            
            return nnzpc;
        });

        //PyObject* colBandwidths() const
        sm.def("colBandwidths", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::UInt32> nnzpc(sm.nCols());

            sm.colBandwidths(get_it(nnzpc));

            return nnzpc;
        });

        //SparseMatrix32 nNonZerosPerBox(PyObject* box_i, PyObject* box_j) const
        sm.def("nNonZerosPerBox", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& box_i, py::array_t<nupic::UInt32>& box_j)
        {
            SparseMatrix32_t result(box_i.size(), box_j.size());

            sm.nNonZerosPerBox(get_it(box_i), get_end(box_i), get_it(box_j), get_end(box_j), result);

            return result;
        });

        //PyObject* max() const
        sm.def("max", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 max_row, max_col;
            nupic::Real32 max_val;
            sm.max(max_row, max_col, max_val);
            
            return py::make_tuple(max_row, max_col, max_val);
        });

        //PyObject* min() const
        sm.def("min", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 min_row, min_col;
            nupic::Real32 min_val;
            sm.min(min_row, min_col, min_val);

            return py::make_tuple(min_row, min_col, min_val);
        });

        //PyObject* rowMin(nupic::UInt32 row_index) const
        sm.def("rowMin", [](const SparseMatrix32_t& sm, nupic::UInt32 row_index)
        {
            nupic::UInt32 idx;
            nupic::Real32 min_val;
            sm.rowMin(row_index, idx, min_val);

            return py::make_tuple(idx, min_val);
        });

        //PyObject* rowMax(nupic::UInt32 row_index) const
        sm.def("rowMax", [](const SparseMatrix32_t& sm, nupic::UInt32 row_index)
        {
            nupic::UInt32 idx;
            nupic::Real32 max_val;
            sm.rowMax(row_index, idx, max_val);
            return py::make_tuple(idx, max_val);
        });

        //PyObject* colMin(nupic::UInt32 col_index) const
        sm.def("colMin", [](const SparseMatrix32_t& sm, nupic::UInt32 col_index)
        {
            nupic::UInt32 idx;
            nupic::Real32 min_val;
            sm.colMin(col_index, idx, min_val);
            return py::make_tuple(idx, min_val);
        });

        //PyObject* colMax(nupic::UInt32 row_index) const
        sm.def("colMax", [](const SparseMatrix32_t& sm, nupic::UInt32 row_index)
        {
            nupic::UInt32 idx;
            nupic::Real32 max_val;
            sm.colMax(row_index, idx, max_val);
            return py::make_tuple(idx, max_val);
        });

        //PyObject* rowMax() const
        sm.def("rowMax", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 n = sm.nRows();
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(n);

            sm.rowMax(get_it(ind), get_it(val));
            
            return py::make_tuple(ind, val);
        });

        //PyObject* rowMin() const
        sm.def("rowMin", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 n = sm.nRows();
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(n);
            sm.rowMin(get_it(ind), get_it(val));

            return py::make_tuple(ind, val);
        });

        //PyObject* colMax() const
        sm.def("colMax", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 n = sm.nCols();
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(n);
            sm.colMax(get_it(ind), get_it(val));
            
            return py::make_tuple(ind, val);
        });

        //PyObject* colMin() const
        sm.def("colMin", [](const SparseMatrix32_t& sm)
        {
            nupic::UInt32 n = sm.nCols();
            py::array_t<nupic::UInt32> ind(n);
            py::array_t<nupic::Real32> val(n);

            sm.colMin(get_it(ind), get_it(val));

            return py::make_tuple(ind, val);
        });

        //PyObject* boxMin(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col) const
        sm.def("boxMin", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col)
        {
            nupic::UInt32 min_row, min_col;
            nupic::Real32 min_val;

            sm.boxMin(begin_row, end_row, begin_col, end_col, min_row, min_col, min_val);

            return py::make_tuple(min_row, min_col, min_val);
        });

        //PyObject* boxMax(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col) const
        sm.def("boxMax", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col)
        {
            nupic::UInt32 max_row, max_col;
            nupic::Real32 max_val;

            sm.boxMax(begin_row, end_row, begin_col, end_col, max_row, max_col, max_val);

            return py::make_tuple(max_row, max_col, max_val);
        });

        //PyObject* whereEqual(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value) const
        sm.def("whereEqual", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value)
        {
            std::vector<nupic::UInt32> rows, cols;
            sm.whereEqual(begin_row, end_row, begin_col, end_col, value,
                std::back_inserter(rows), std::back_inserter(cols));

            py::tuple toReturn(rows.size());

            for (size_t i = 0; i != rows.size(); ++i)
            {
                toReturn[i] = py::make_tuple(rows[i], cols[i]);
            }

            return toReturn;
        });

        //PyObject* whereGreater(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value) const
        sm.def("whereGreater", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value)
        {
            std::vector<nupic::UInt32> rows, cols;
            sm.whereGreater(begin_row, end_row, begin_col, end_col, value,
                std::back_inserter(rows), std::back_inserter(cols));

            py::array_t<nupic::UInt32> toReturn({ static_cast<int>(rows.size()), 2 });
            auto r = toReturn.mutable_unchecked<2>();

            for (size_t i = 0; i != rows.size(); ++i)
            {
                r(i, 0) = rows[i];
                r(i, 1) = cols[i];
            }

            return toReturn;
        });

        ////PyObject* whereGreaterEqual(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value) const
        sm.def("whereGreaterEqual", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value)
        {
            std::vector<nupic::UInt32> rows, cols;
            sm.whereGreaterEqual(begin_row, end_row, begin_col, end_col, value,
                std::back_inserter(rows), std::back_inserter(cols));

            py::array_t<nupic::UInt32> toReturn({ static_cast<int>(rows.size()), 2 });
            auto r = toReturn.mutable_unchecked<2>();

            for (size_t i = 0; i != rows.size(); ++i) {
                r(i, 0) = rows[i];
                r(i, 1) = cols[i];
            }
            return toReturn;
        });

        //nupic::UInt32 countWhereGreaterOrEqual(nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value) const
        sm.def("countWhereGreaterOrEqual", [](const SparseMatrix32_t& sm, nupic::UInt32 begin_row, nupic::UInt32 end_row, nupic::UInt32 begin_col, nupic::UInt32 end_col, const nupic::Real32& value)
        {
            std::vector<nupic::UInt32> rows, cols;
            return sm.countWhereGreaterEqual(begin_row, end_row, begin_col, end_col, value);
        });

        //void permuteRows(PyObject* py_permutation)
        sm.def("permuteRows", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& permutation)
        {
            sm.permuteRows(get_it(permutation));
        });

        //void permuteCols(PyObject* py_permutation)
        sm.def("permuteCols", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& permutation)
        {
            sm.permuteCols(get_it(permutation));
        });

        //PyObject* rowSums() const
        sm.def("rowSums", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nRows());

            sm.rowSums(get_it(m));

            return m;
        });

        //PyObject* colSums() const
        sm.def("colSums", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nCols());
            
            sm.colSums(get_it(m));

            return m;
        });

        //PyObject* addRows(PyObject* whichRows) const
        sm.def("addRows", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& whichRows)
        {
            py::array_t<nupic::Real32> res(sm.nCols());

            sm.addRows(get_it(whichRows), get_end(whichRows), get_it(res), get_end(res));

            return res;
        });

        //PyObject* addListOfRows(PyObject* py_whichRows) const
        sm.def("addListOfRows", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& whichRows)
        {
            py::array_t<nupic::Real32> res(sm.nCols());
            
            sm.addListOfRows(get_it(whichRows), get_end(whichRows), get_it(res), get_end(res));

            return res;
        });

        //PyObject* rowProds() const
        sm.def("rowProds", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nRows());
            
            sm.rowProds(get_it(m));
            
            return m;
        });

        //PyObject* colProds() const
        sm.def("colProds", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nCols());
            
            sm.colProds(get_it(m));

            return m;
        });

        //PyObject* logRowSums() const
        sm.def("logRowSums", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nRows());

            sm.logRowSums(get_it(m), get_end(m));

            return m;
        });

        //PyObject* logColSums() const
        sm.def("logColSums", [](const SparseMatrix32_t& sm)
        {
            py::array_t<nupic::Real32> m(sm.nCols());

            sm.logColSums(get_it(m), get_end(m));

            return m;
        });

        //void scaleRows(PyObject* py_s)
        sm.def("scaleRows", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& s)
        {
            sm.scaleRows(get_it(s));
        });

        //void scaleCols(PyObject* py_s)
        sm.def("scaleCols", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& s)
        {
            sm.scaleCols(get_it(s));
        });

        //void normalizeBlockByRows(PyObject* py_inds, nupic::Real32 val = -1.0, nupic::Real32 eps_n = 1e-6)
        sm.def("normalizeBlockByRows", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& inds, nupic::Real32 val, nupic::Real32 eps_n)
        {
            sm.normalizeBlockByRows(get_it(inds), get_end(inds), val, eps_n);
        }, "", py::arg("inds"), py::arg("val") = -1.0, py::arg("eps_n") = 1e-6);

        //void normalizeBlockByRows_binary(PyObject* py_inds, nupic::Real32 val = -1.0, nupic::Real32 eps_n = 1e-6)
        sm.def("normalizeBlockByRows_binary", [](SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& inds, nupic::Real32 val, nupic::Real32 eps_n)
        {
            sm.normalizeBlockByRows_binary(get_it(inds), get_end(inds), val, eps_n);
        }, "", py::arg("inds"), py::arg("val") = -1.0, py::arg("eps_n") = 1e-6);

        //void axby(nupic::UInt32 row, nupic::Real32 a, nupic::Real32 b, PyObject *xIn)
        sm.def("axby", [](SparseMatrix32_t& sm, nupic::UInt32 row, nupic::Real32 a, nupic::Real32 b, py::array_t<nupic::Real32>& xIn)
        {
            sm.axby(row, a, b, get_it(xIn));
        });

        //void axby(nupic::Real32 a, nupic::Real32 b, PyObject *xIn)
        sm.def("axby", [](SparseMatrix32_t& sm, nupic::Real32 a, nupic::Real32 b, py::array_t<nupic::Real32>& xIn)
        {
            sm.axby(a, b, get_it(xIn));
        });

        //nupic::Real32 rightVecProd(nupic::UInt32 row, PyObject *xIn) const
        sm.def("rightVecProd", [](const SparseMatrix32_t& sm, nupic::UInt32 row, py::array_t<nupic::Real32>& xIn)
        {
            return sm.rightVecProd(row, get_it(xIn));
        }, "Computes the dot product of the given row with the given vector.");

        //inline PyObject* rightVecProd(PyObject *xIn) const
        sm.def("rightVecProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nRows());

            sm.rightVecProd(get_it(xIn), get_it(y));

            return y;
        }, "Regular matrix vector multiplication, with allocation of the result.");

        //inline void rightVecProd_fast(PyObject *xIn, PyObject *yOut) const
        sm.def("rightVecProd_fast", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn, py::array_t<nupic::Real32>& yOut)
        {
            sm.rightVecProd(get_it(xIn), get_it(yOut));
        }, "Regular matrix vector multiplication, with allocation of the result. Fast because doesn't go through NumpyVectorT and doesn't allocate memory.");

        //PyObject* rightVecProd(PyObject* pyRows, PyObject *xIn) const
        sm.def("rightVecProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& Rows, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(Rows.size());
            sm.rightVecProd(get_it(Rows), get_end(Rows), get_it(xIn), get_it(y));
            return y;
        }, "Matrix vector product on the right side, only for some rows.");

        //SparseMatrix32 blockRightVecProd(nupic::UInt32 block_size, PyObject* xIn) const
        sm.def("blockRightVecProd", [](const SparseMatrix32_t& sm, nupic::UInt32 block_size, py::array_t<nupic::Real32>& xIn)
        {
            SparseMatrix32_t result;

            sm.blockRightVecProd(block_size, get_it(xIn), result);

            return result;
        });

        //nupic::Real32 leftVecProd(nupic::UInt32 col, PyObject *xIn) const
        sm.def("leftVecProd", [](const SparseMatrix32_t& sm, nupic::UInt32 col, py::array_t<nupic::Real32>& xIn)
        {
            return sm.leftVecProd(col, get_it(xIn));
        }, "Dot product of column col and vector xIn.");

        //PyObject* leftVecProd(PyObject *xIn) const
        sm.def("leftVecProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nCols());
            
            sm.leftVecProd(get_it(xIn), get_it(y));
            
            return y;
        }, "Vector matrix product on the left, i.e. dot product of xIn and each column of the matrix.");

        //PyObject* leftVecProd(PyObject* pyCols, PyObject *xIn) const
        sm.def("leftVecProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& Cols, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(Cols.size());

            sm.leftVecProd(get_it(Cols), get_end(Cols), get_it(xIn), get_it(y));

            return y;
        });

        //PyObject* leftVecProd_binary(PyObject* pyCols, PyObject *xIn) const
        sm.def("leftVecProd_binary", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& Cols, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(Cols.size());

            sm.leftVecProd_binary(get_it(Cols), get_end(Cols), get_it(xIn), get_it(y));

            return y;
        }, "Binary search for the columns.");

        //PyObject* rightDenseMatProd(PyObject* mIn) const
        sm.def("rightDenseMatProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(sm.nRows(), m.nCols());

            sm.rightDenseMatProd(m, r);

            return r.get_py_array();
        });

        //PyObject* rightDenseMatProdAtNZ(PyObject* mIn) const
        sm.def("rightDenseMatProdAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(sm.nRows(), m.nCols());

            sm.rightDenseMatProdAtNZ(m, r);

            return r.get_py_array();
        });

        //PyObject* denseMatExtract(PyObject* mIn) const
        sm.def("denseMatExtract", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(sm.nRows(), m.nCols());

            sm.denseMatExtract(m, r);

            return r.get_py_array();
        });

        //PyObject* leftDenseMatProd(PyObject* mIn) const
        sm.def("leftDenseMatProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(sm.nRows(), m.nCols());

            for (int i = 0; i != m.nRows(); ++i)
                sm.leftVecProd(m.get_row(i), r.get_row(i));

            return r.get_py_array();
        });

        //void elementRowAdd(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementRowAdd", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementRowAdd(i, get_it(xIn));
        });

        //void elementRowSubtract(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementRowSubtract", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementRowSubtract(i, get_it(xIn));
        });

        //void elementRowMultiply(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementRowMultiply", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementRowMultiply(i, get_it(xIn));
        });

        //void elementRowDivide(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementRowDivide", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementRowDivide(i, get_it(xIn));
        });

        //void elementColAdd(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementColAdd", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementColAdd(i, get_it(xIn));
        });

        //void elementColSubtract(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementColSubtract", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementColSubtract(i, get_it(xIn));
        });

        //void elementColMultiply(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementColMultiply", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementColMultiply(i, get_it(xIn));
        });

        //void elementColDivide(nupic::UInt32 i, PyObject* xIn)
        sm.def("elementColDivide", [](SparseMatrix32_t& sm, nupic::UInt32 i, py::array_t<nupic::Real32>& xIn)
        {
            sm.elementColDivide(i, get_it(xIn));
        });

        //void elementMultiply(PyObject* mIn)
        sm.def("elementMultiply", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            sm.elementMultiply(get_it(mIn));
        });

        //////--------------------------------------------------------------------------------
        ////// AtNZ operations, i.e. considering the sparse matrix as a 0/1 sparse matrix.
        //////--------------------------------------------------------------------------------

        //PyObject* rightVecProdAtNZ(PyObject* xIn) const
        sm.def("rightVecProdAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nRows());

            sm.rightVecProdAtNZ(get_it(xIn), get_it(y));

            return y;
        });

        //PyObject* leftVecProdAtNZ(PyObject* xIn) const
        sm.def("leftVecProdAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nCols());

            sm.leftVecProdAtNZ(get_it(xIn), get_it(y));

            return y;
        });

        // rightVecSumAtNZ
        sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& denseArray)
        {
            py::array_t<nupic::Real32> out(sm.nRows());

            sm.rightVecSumAtNZ(get_it(denseArray), get_it(out));

            return out;
        });

        //inline void _rightVecSumAtNZSparse(PyObject* py_sparseBinaryArray, PyObject* py_out) const
        sm.def("rightVecSumAtNZSparse", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& sparseBinaryArray, py::array_t<nupic::Int32>& out)
        {
            //if out is None :
            //out = numpy.empty(self.nRows(), dtype = "int32")
            //else:
            //assert out.dtype == "int32"

            //    self._rightVecSumAtNZSparse(sparseBinaryArray, out)

            // _rightVecSumAtNZSparse

            NTA_ASSERT(out.size() >= sm.nRows());

            sm.rightVecSumAtNZSparse(get_it(sparseBinaryArray), get_it(sparseBinaryArray), get_it(out));

            return out;
        });

        //inline void _rightVecSumAtNZGtThreshold(PyObject* py_denseArray, nupic::Real32 threshold, PyObject* py_out) const
        sm.def("rightVecSumAtNZGtThreshold", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& denseArray, nupic::Real32 threshold
            , py::array_t<nupic::Real32>& out)
        {
            NTA_ASSERT(out.size() >= sm.nRows());

            sm.rightVecSumAtNZGtThreshold(get_it(denseArray), get_it(out), threshold);

            return out;
        }, "Deprecated. Use rightVecSumAtNZGtThreshold with an 'out' specified.");

        //inline void _rightVecSumAtNZGtThresholdSparse(PyObject* py_sparseBinaryArray, nupic::Real32 threshold, PyObject* py_out) const
        sm.def("rightVecSumAtNZGtThresholdSparse", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& sparseBinaryArray, nupic::Real32 threshold
            , py::array_t<nupic::Int32>& out)
        {
            NTA_ASSERT(out.size() >= sm.nRows());

            sm.rightVecSumAtNZGtThresholdSparse(get_it(sparseBinaryArray), get_end(sparseBinaryArray), get_it(out), threshold);

            return out;
        });

        //inline void _rightVecSumAtNZGteThreshold(PyObject* py_denseArray, nupic::Real32 threshold, PyObject* py_out) const
        sm.def("rightVecSumAtNZGteThreshold", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& denseArray, nupic::Real32 threshold
            , py::array_t<nupic::Real32>& out)
        {
            NTA_ASSERT(out.size() >= sm.nRows());

            sm.rightVecSumAtNZGteThreshold(get_it(denseArray), get_it(out), threshold);

            return out;
        });

        //inline void _rightVecSumAtNZGteThresholdSparse(PyObject* py_sparseBinaryArray, nupic::Real32 threshold, PyObject* py_out) const
        sm.def("rightVecSumAtNZGteThresholdSparse", [](const SparseMatrix32_t& sm, py::array_t<nupic::UInt32>& sparseBinaryArray, nupic::Real32 threshold
            , py::array_t<nupic::Int32>& out)
        {
            NTA_ASSERT(out.size() >= sm.nRows());

            sm.rightVecSumAtNZGteThresholdSparse(get_it(sparseBinaryArray), get_end(sparseBinaryArray), get_it(out), threshold);

            return out;
        });

        //inline PyObject* leftVecSumAtNZ(PyObject* xIn) const
        sm.def("leftVecSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nCols());
            
            sm.leftVecSumAtNZ(get_it(xIn), get_it(y));
            
            return y;
        }, "Regular matrix vector multiplication on the left side, assuming that the values of the non-zeros are all 1, so that we can save actually computing the multiplications. Allocates the result.");

        //inline void leftVecSumAtNZ_fast(PyObject *xIn, PyObject *yOut) const
        sm.def("leftVecSumAtNZ_fast", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn, py::array_t<nupic::Real32>& yOut)
        {
            sm.leftVecSumAtNZ(get_it(xIn), get_it(yOut));
        }, "Regular matrix vector multiplication on the left, without allocation of the result, assuming that the values of the non-zeros are always 1 in the sparse matrix, so that we can save computing multiplications explicitly. Also fast because doesn't go through NumpyVectorT and doesn't allocate memory.");

        //PyObject* rightDenseMatProdAtNZ(PyObject* mIn) const
        sm.def("rightDenseMatProdAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nRows());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.rightVecProdAtNZ(m.get_row(i), r.get_row(i));
            }

            return r.get_py_array();
        });

        //PyObject* leftDenseMatProdAtNZ(PyObject* mIn) const
        sm.def("leftDenseMatProdAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nCols());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.leftVecProdAtNZ(m.get_row(i), r.get_row(i));
            }
            
            return r.get_py_array();
        });

        //PyObject* rightDenseMatSumAtNZ(PyObject* mIn) const
        sm.def("rightDenseMatSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nRows());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.rightVecSumAtNZ(m.get_row(i), r.get_row(i));
            }
            
            return r.get_py_array();
        });

        //PyObject* leftDenseMatSumAtNZ(PyObject* mIn) const
        sm.def("leftDenseMatSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nCols());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.leftVecSumAtNZ(m.get_row(i), r.get_row(i));
            }
            
            return r.get_py_array();
        });

        //PyObject* rightDenseMatMaxAtNZ(PyObject* mIn) const
        sm.def("rightDenseMatMaxAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nRows());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.rightVecMaxAtNZ(m.get_row(i), r.get_row(i));
            }
            
            return r.get_py_array();
        });

        //PyObject* leftDenseMatMaxAtNZ(PyObject* mIn) const
        sm.def("leftDenseMatMaxAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& mIn)
        {
            Numpy_Matrix<nupic::Real32> m(mIn.request());
            Numpy_Matrix<nupic::Real32> r(m.nRows(), sm.nCols());

            for (int i = 0; i != m.nRows(); ++i)
            {
                sm.leftVecMaxAtNZ(m.get_row(i), r.get_row(i));
            }
            
            return r.get_py_array();
        });

        //PyObject* vecArgMaxAtNZ(PyObject *xIn)
        sm.def("vecArgMaxAtNZ", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::UInt32> y(sm.nRows());

            sm.vecArgMaxAtNZ(get_it(xIn), get_it(y));

            return y;
        });

        //PyObject* vecMaxAtNZ(PyObject *xIn)
        sm.def("vecMaxAtNZ", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nRows());
            
            sm.vecMaxAtNZ(get_it(xIn), get_it(y));
            
            return y;
        });

        //PyObject* rowVecProd(PyObject* xIn, nupic::Real32 lb = nupic::Epsilon) const
        sm.def("rowVecProd", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn, nupic::Real32 lb)
        {
            py::array_t<nupic::Real32> y(sm.nRows());

            sm.rowVecProd(get_it(xIn), get_it(y));

            return y;
        }, "", py::arg("xIn"), py::arg("lb") = nupic::Epsilon);

        //PyObject* vecMaxProd(PyObject *xIn)
        sm.def("vecMaxProd", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::Real32> y(sm.nRows());

            sm.vecMaxProd(get_it(xIn), get_it(y));

            return y;
        });

        //PyObject* vecArgMaxProd(PyObject *xIn)
        sm.def("vecArgMaxProd", [](SparseMatrix32_t& sm, py::array_t<nupic::Real32>& xIn)
        {
            py::array_t<nupic::UInt32> y(sm.nRows());

            sm.vecArgMaxProd(get_it(xIn), get_it(y));

            return y;
        });

        //PyObject* getNonZerosSorted(nupic::Int n = -1, bool ascending_values = true) const
        sm.def("getNonZerosSorted", [](const SparseMatrix32_t& sm, nupic::Int n, bool ascending_values)
        {
            typedef nupic::ijv<nupic::UInt32, nupic::Real32> IJV;

            nupic::UInt32 nnz = sm.nNonZeros();
            nupic::UInt32 N = n == -1 ? nnz : n;
            std::vector<IJV> ijvs(N);
            if (ascending_values)
            {
                sm.getNonZerosSorted(ijvs.begin(), N, IJV::greater_value());
            }
            else
            {
                sm.getNonZerosSorted(ijvs.begin(), N, IJV::less_value());
            }
            
            py::tuple toReturn(N);

            for (nupic::UInt32 i = 0; i != N; ++i)
            {
                toReturn[i] = py::make_tuple(ijvs[i].i(), ijvs[i].j(), ijvs[i].v());
            }

            return toReturn;
        }, "", py::arg("n") = -1, py::arg("ascending_values") = true);

        //PyObject* threshold(nupic::Real32 threshold, bool getCuts = false)
        sm.def("threshold", [](SparseMatrix32_t& sm, nupic::Real32 threshold, bool getCuts)
        {
            if (!getCuts)
            {
                sm.threshold(threshold);
                return py::tuple();
            }

            std::vector<nupic::UInt32> cut_i, cut_j;
            std::vector<nupic::Real32> cut_nz;
            nupic::UInt32 c = 0;
            c = sm.threshold(threshold,
                std::back_inserter(cut_i),
                std::back_inserter(cut_j),
                std::back_inserter(cut_nz));
            
            py::tuple toReturn(c);
            
            for (nupic::UInt32 i = 0; i != c; ++i)
            {
                toReturn[i] = py::make_tuple(cut_i[i], cut_j[i], cut_nz[i]);
            }
 
            return toReturn;
        }, "", py::arg("threshold"), py::arg("getCuts") = false);

        //PyObject* toPyString() const
        sm.def("toPyString", [](const SparseMatrix32_t& sm)
        {
            std::stringstream s;

            sm.toCSR(s);

            return s.str();
        });

        //bool fromPyString(PyObject *s)
        sm.def("fromPyString", [](SparseMatrix32_t& sm, const std::string& s)
        {
            if (s.empty() == false)
            {
                std::istringstream ss(s);
                sm.fromCSR(ss);
                return true;
            }

            throw std::runtime_error("Failed to read SparseMatrix state from string.");
            return false;
        });


        sm.def("__eq__", [](const SparseMatrix32_t& sm, const SparseMatrix32_t& other)
        {
            return sm == other;
        });

        sm.def("__eq__", [](const SparseMatrix32_t& sm, const SparseMatrix32_t& other)
        {
            return sm != other;
        });

        //////////////////////

        sm.def("initializeWithFixedNNZR", [](SparseMatrix32_t self, nupic::UInt32 nnzr, nupic::Real32 v, nupic::UInt32 mode, nupic::UInt32 seed)
        {
            self.initializeWithFixedNNZR(nnzr, v, mode, seed);
        }, "Initialize a sparse matrix with a fixed number of non-zeros on each row."
            , py::arg("nnzr"), py::arg("v") = 1.0, py::arg("mode") = 0, py::arg("seed") = 42);


    }

} // namespace nupix_ext
