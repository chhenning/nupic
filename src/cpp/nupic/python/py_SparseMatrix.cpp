
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

        //void addColNZ(PyObject *ind, PyObject *nz)

        //void deleteRows(PyObject *rowIndices)

        //void deleteCols(PyObject *colIndices)

        // getRow
        sm.def("getRow", [](SparseMatrix32_t& sm, nupic::UInt row)
        {
            const auto ncols = sm.nCols();
            py::array_t<nupic::Real> dense_row(ncols);
            sm.getRowToDense(row, get_it(dense_row));

            return dense_row;
        });




        //PyObject* getCol(nupic::UInt ## N1 col) const

        //PyObject* getDiagonal() const

        //PyObject* rowNonZeros(nupic::UInt ## N1 row) const

        //PyObject* rowNonZeroIndices(nupic::UInt ## N1 row) const

        //PyObject* colNonZeros(nupic::UInt ## N1 col) const

        //PyObject* nonZeroRows() const

        //PyObject* zeroRows() const

        //PyObject* nonZeroCols() const

        //PyObject* zeroCols() const

        //PyObject* zeroRowAndCol() const

        //void setElements(PyObject* py_i, PyObject* py_j, PyObject* py_v)

        //PyObject* getElements(PyObject* py_i, PyObject* py_j) const

        //// Sets on the outer product of the passed ranges.
        //void setOuter(PyObject* py_i, PyObject* py_j, PyObject* py_v)

        //// Get on the outer products of the passed ranges.
        //SparseMatrix ## N2 getOuter(PyObject* py_i, PyObject* py_j) const

        //// Returns the positions and values of all the non-zeros stored
        //// in this matrix. The result can be either three lists ((i), (j), (v))
        //// or one list of triples (i,j,v).
        //PyObject* getAllNonZeros(bool three_lists = false) const

        //void setAllNonZeros(nupic::UInt ## N1 nrows, nupic::UInt ## N1 ncols, PyObject* py_i, PyObject* py_j, PyObject* py_v, bool sorted = true)

        //PyObject* getNonZerosInBox(nupic::UInt ## N1 row_begin, nupic::UInt ## N1 row_end, nupic::UInt ## N1 col_begin, nupic::UInt ## N1 col_end) const

        //PyObject* tolist() const

        //void setSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 j_begin, const SparseMatrix ## N2& other)

        //void setSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 j_begin, PyObject* py_other)

        //SparseMatrix ## N2 getSlice(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 i_end, nupic::UInt ## N1 j_begin, nupic::UInt ## N1 j_end) const

        //SparseMatrix ## N2 getSlice2(nupic::UInt ## N1 i_begin, nupic::UInt ## N1 i_end, nupic::UInt ## N1 j_begin, nupic::UInt ## N1 j_end) const

        //inline void setRowsToZero(PyObject* py_rows)

        //inline void setColsToZero(PyObject* py_cols)

        //inline void setDiagonal(PyObject* py_v)

        //void incrementOnOuterWNZ(PyObject* py_i, PyObject* py_j, nupic::Real ## N2 delta = 1)

        //void incrementOnOuterWNZWThreshold(PyObject* py_i, PyObject* py_j, nupic::Real ## N2 threshold, nupic::Real ## N2 delta = 1)

        //void _incrementNonZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 delta)

        //void _incrementNonZerosOnRowsExcludingCols(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 delta)

        //void _setZerosOnOuter(PyObject* py_rows, PyObject* py_cols, nupic::Real ## N2 value)

        //void _setRandomZerosOnOuter_singleCount(PyObject* py_rows, PyObject* py_cols, nupic::Int ## N1 numNewNonZeros, nupic::Real ## N2 value, nupic::Random& rng)

        //void _setRandomZerosOnOuter_multipleCounts(PyObject* py_rows, PyObject* py_cols, PyObject* py_newNonZeroCounts, nupic::Real ## N2 value, nupic::Random& rng)

        //void _increaseRowNonZeroCountsOnOuterTo(PyObject* py_rows, PyObject* py_cols, nupic::Int ## N1 numDesiredNonZeros, nupic::Real ## N2 initialValue, nupic::Random& rng)

        //void _clipRowsBelowAndAbove(PyObject* py_rows, nupic::Real ## N2 a, nupic::Real ## N2 b)

        //PyObject* _nNonZerosPerRow_allRows() const

        //PyObject* _nNonZerosPerRow(PyObject* py_rows)

        //PyObject* _nNonZerosPerRowOnCols(PyObject* py_rows, PyObject* py_cols)

        //PyObject* nNonZerosPerCol() const

        //PyObject* rowBandwidths() const

        //PyObject* colBandwidths() const

        //SparseMatrix ## N1 nNonZerosPerBox(PyObject* box_i, PyObject* box_j) const

        //PyObject* max() const

        //PyObject* min() const

        //PyObject* rowMin(nupic::UInt ## N1 row_index) const

        //PyObject* rowMax(nupic::UInt ## N1 row_index) const

        //PyObject* colMin(nupic::UInt ## N1 col_index) const

        //PyObject* colMax(nupic::UInt ## N1 row_index) const

        //PyObject* rowMax() const

        //PyObject* rowMin() const

        //PyObject* colMax() const

        //PyObject* colMin() const

        //PyObject* boxMin(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col) const

        //PyObject* boxMax(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col) const

        //PyObject* whereEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const

        //PyObject* whereGreater(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const

        //PyObject* whereGreaterEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const

        //nupic::UInt32 countWhereGreaterOrEqual(nupic::UInt ## N1 begin_row, nupic::UInt ## N1 end_row, nupic::UInt ## N1 begin_col, nupic::UInt ## N1 end_col, const nupic::Real ## N2& value) const

        //void permuteRows(PyObject* py_permutation)

        //void permuteCols(PyObject* py_permutation)

        //PyObject* rowSums() const

        //PyObject* colSums() const

        //PyObject* addRows(PyObject* whichRows) const

        //PyObject* addListOfRows(PyObject* py_whichRows) const

        //PyObject* rowProds() const

        //PyObject* colProds() const

        //PyObject* logRowSums() const

        //PyObject* logColSums() const

        //void scaleRows(PyObject* py_s)

        //void scaleCols(PyObject* py_s)

        //void normalizeBlockByRows(PyObject* py_inds, nupic::Real ## N2 val = -1.0, nupic::Real ## N2 eps_n = 1e-6)

        //void normalizeBlockByRows_binary(PyObject* py_inds, nupic::Real ## N2 val = -1.0, nupic::Real ## N2 eps_n = 1e-6)

        //void axby(nupic::UInt ## N1 row, nupic::Real ## N2 a, nupic::Real ## N2 b, PyObject *xIn)

        //void axby(nupic::Real ## N2 a, nupic::Real ## N2 b, PyObject *xIn)

        //// Computes the dot product of the given row with the given vector.
        //nupic::Real ## N2 rightVecProd(nupic::UInt ## N1 row, PyObject *xIn) const

        //// Regular matrix vector multiplication, with allocation of the result.
        //inline PyObject* rightVecProd(PyObject *xIn) const

        //// Regular matrix vector multiplication, with allocation of the result.
        //// Fast because doesn't go through NumpyVectorT and doesn't allocate
        //// memory.
        //inline void rightVecProd_fast(PyObject *xIn, PyObject *yOut) const

        //// Matrix vector product on the right side, only for some rows.
        //PyObject* rightVecProd(PyObject* pyRows, PyObject *xIn) const

        //SparseMatrix ## N2 blockRightVecProd(nupic::UInt ## N1 block_size, PyObject* xIn) const

        //// Dot product of column col and vector xIn.
        //nupic::Real ## N2 leftVecProd(nupic::UInt ## N1 col, PyObject *xIn) const

        //// Vector matrix product on the left, i.e. dot product of xIn and
        //// each column of the matrix.
        //PyObject* leftVecProd(PyObject *xIn) const

        //PyObject* leftVecProd(PyObject* pyCols, PyObject *xIn) const

        //// Binary search for the columns.
        //PyObject* leftVecProd_binary(PyObject* pyCols, PyObject *xIn) const

        //PyObject* rightDenseMatProd(PyObject* mIn) const

        //PyObject* rightDenseMatProdAtNZ(PyObject* mIn) const

        //PyObject* denseMatExtract(PyObject* mIn) const

        //PyObject* leftDenseMatProd(PyObject* mIn) const

        //void elementRowAdd(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementRowSubtract(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementRowMultiply(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementRowDivide(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementColAdd(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementColSubtract(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementColMultiply(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementColDivide(nupic::UInt ## N1 i, PyObject* xIn)

        //void elementMultiply(PyObject* mIn)

        ////--------------------------------------------------------------------------------
        //// AtNZ operations, i.e. considering the sparse matrix as a 0/1 sparse matrix.
        ////--------------------------------------------------------------------------------
        //PyObject* rightVecProdAtNZ(PyObject* xIn) const

        //PyObject* leftVecProdAtNZ(PyObject* xIn) const

        // rightVecSumAtNZ
        sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t self, py::array_t<nupic::Real32>& denseArray)
        {
            py::array_t<nupic::Real32> out(self.nRows());
            self.rightVecSumAtNZ(get_it(denseArray), get_it(out));

            return out;
        });


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
