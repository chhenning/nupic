#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/algorithms/Cell.hpp>
#include <nupic/algorithms/Cells4.hpp>
#include <nupic/algorithms/Segment.hpp>
#include <nupic/algorithms/SegmentUpdate.hpp>

#include "py_utils.hpp"

namespace py = pybind11;

namespace nupic_ext
{
    void init_Cells4(py::module& m)
    {
        //////////////////
        // Cell
        //////////////////
        typedef nupic::algorithms::Cells4::Cell Cell_t;

        py::class_<Cell_t> py_cell(m, "Cell");
        py_cell.def(py::init<>());

        py_cell.def("getSegment", &Cell_t::getSegment);


        //////////////////
        // Segment
        //////////////////
        typedef nupic::algorithms::Cells4::Segment Segment_t;

        py::class_<Segment_t> py_segment(m, "Segment");

        py_segment.def(py::init<>());

        py_segment.def("size", &Segment_t::size);
        py_segment.def("getSrcCellIdx", &Segment_t::getSrcCellIdx);
        py_segment.def("getPermanence", &Segment_t::getPermanence);
        

        //////////////////
        // Cells4
        //////////////////
        typedef nupic::algorithms::Cells4::Cells4 Cells4_t;

        py::class_<Cells4_t> py_cells4(m, "Cells4");

        py_cells4.def(py::init<UInt   // nColumns =0, 
            , UInt // nCellsPerCol =0,
            , UInt // activationThreshold =1,
            , UInt // minThreshold =1,
            , UInt // newSynapseCount =1,
            , UInt // segUpdateValidDuration =1,
            , Real // permInitial =.5,
            , Real // permConnected =.8,
            , Real // permMax =1,
            , Real // permDec =.1,
            , Real // permInc =.1,
            , Real // globalDecay =0,
            , bool // doPooling =false,
            , int  // seed =-1,
            , bool // initFromCpp =false,
            , bool // checkSynapseConsistency =false
        >()
            , py::arg("nColumns") = 0
            , py::arg("nCellsPerCol") = 0
            , py::arg("activationThreshold") = 1
            , py::arg("minThreshold") = 1
            , py::arg("newSynapseCount") = 1
            , py::arg("segUpdateValidDuration") = 1
            , py::arg("permInitial") = .5
            , py::arg("permConnected") = .8
            , py::arg("permMax") = 1
            , py::arg("permDec") = .1
            , py::arg("permInc") = .1
            , py::arg("globalDecay") = 0
            , py::arg("doPooling") = false
            , py::arg("seed") = -1
            , py::arg("initFromCpp") = false
            , py::arg("checkSynapseConsistency") = false);

            // def initialize(self, nColumns = 0, nCellsPerCol = 0, activationThreshold = 1, minThreshold = 1, newSynapseCount = 1, segUpdateValidDuration = 1, permInitial = .5, permConnected = .8, permMax = 1, permDec = .1, permInc = .1, globalDecay = .1, doPooling = False, initFromCpp = False, checkSynapseConsistency = False) :
        py_cells4.def("initialize"
            , &Cells4_t::initialize
            , py::arg("nColumns") = 0
            , py::arg("nCellsPerCol") = 0
            , py::arg("activationThreshold") = 1
            , py::arg("minThreshold") = 1
            , py::arg("newSynapseCount") = 1
            , py::arg("segUpdateValidDuration") = 1
            , py::arg("permInitial") = .5
            , py::arg("permConnected") = .8
            , py::arg("permMax") = 1
            , py::arg("permDec") = .1
            , py::arg("permInc") = .1
            , py::arg("globalDecay") = .1
            , py::arg("doPooling") = false
            , py::arg("initFromCpp") = false
            , py::arg("checkSynapseConsistency") = false);

        py_cells4.def("version", &Cells4_t::version);

        py_cells4.def("getStatePointers", /*&Cells4_t::getStatePointers*/ 
            [](Cells4_t& self
            , py::array_t<nupic::Byte>& activeT
            , py::array_t<nupic::Byte>& activeT1
            , py::array_t<nupic::Byte>& predT
            , py::array_t<nupic::Byte>& predT1
            , py::array_t<nupic::Real32>& colConfidenceT
            , py::array_t<nupic::Real32>& colConfidenceT1
            , py::array_t<nupic::Real32>& confidenceT
            , py::array_t<nupic::Real32>& confidenceT1
            )
        {
            throw std::runtime_error("Not implemented."); 
        });


        py_cells4.def("getLearnStatePointers", /*&Cells4_t::getLearnStatePointers*/
            [](Cells4_t& self
            , py::array_t<nupic::Byte>& activeT
            , py::array_t<nupic::Byte>& activeT1
            , py::array_t<nupic::Byte>& predT
            , py::array_t<nupic::Byte>& predT1
            )
        {
            throw std::runtime_error("Not implemented.");
        });

        py_cells4.def("nSegments", &Cells4_t::nSegments);
        py_cells4.def("nCells", &Cells4_t::nCells);
        py_cells4.def("nColumns", &Cells4_t::nColumns);
        py_cells4.def("nCellsPerCol", &Cells4_t::nCellsPerCol);
        py_cells4.def("getMinThreshold", &Cells4_t::getMinThreshold);
        py_cells4.def("getPermConnected", &Cells4_t::getPermConnected);
        py_cells4.def("getVerbosity", &Cells4_t::getVerbosity);
        py_cells4.def("getMaxAge", &Cells4_t::getMaxAge);
        py_cells4.def("getPamLength", &Cells4_t::getPamLength);
        py_cells4.def("getMaxInfBacktrack", &Cells4_t::getMaxInfBacktrack);
        py_cells4.def("getMaxLrnBacktrack", &Cells4_t::getMaxLrnBacktrack);
        py_cells4.def("getPamCounter", &Cells4_t::getPamCounter);
        py_cells4.def("getMaxSeqLength", &Cells4_t::getMaxSeqLength);
        py_cells4.def("getAvgLearnedSeqLength", &Cells4_t::getAvgLearnedSeqLength);
        py_cells4.def("getNonEmptySegList", &Cells4_t::getNonEmptySegList);
        py_cells4.def("getNLrnIterations", &Cells4_t::getNLrnIterations);
        py_cells4.def("getMaxSegmentsPerCell", &Cells4_t::getMaxSegmentsPerCell);
        py_cells4.def("getMaxSynapsesPerSegment", &Cells4_t::getMaxSynapsesPerSegment);
        py_cells4.def("getCheckSynapseConsistency", &Cells4_t::getCheckSynapseConsistency);

        py_cells4.def("setMaxInfBacktrack", &Cells4_t::setMaxInfBacktrack);
        py_cells4.def("setMaxLrnBacktrack", &Cells4_t::setMaxLrnBacktrack);
        py_cells4.def("setVerbosity", &Cells4_t::setVerbosity);
        py_cells4.def("setMaxAge", &Cells4_t::setMaxAge);
        py_cells4.def("setMaxSeqLength", &Cells4_t::setMaxSeqLength);
        py_cells4.def("setCheckSynapseConsistency", &Cells4_t::setCheckSynapseConsistency);

        py_cells4.def("setMaxSegmentsPerCell", &Cells4_t::setMaxSegmentsPerCell);
        py_cells4.def("setMaxSynapsesPerCell", &Cells4_t::setMaxSynapsesPerCell);
        py_cells4.def("setPamLength", &Cells4_t::setPamLength);

        py_cells4.def("nSegmentsOnCell", &Cells4_t::nSegmentsOnCell, "Returns the number of segments currently in use on the given cell.");
        py_cells4.def("nSynapses", &Cells4_t::nSynapses);

        // def __nSegmentsOnCell(self, cellIdx) :
        
        py_cells4.def("nSynapsesInCell", &Cells4_t::nSynapsesInCell, "Total number of synapses in a given cell (at at given point, changes all the time).");

        py_cells4.def("getCell", &Cells4_t::getCell);
        py_cells4.def("getCellIdx", &Cells4_t::getCellIdx);

        py_cells4.def("getSegment", &Cells4_t::getSegment, py::return_value_policy::reference);


        // def segment(self, cellIdx, segIdx):

        py_cells4.def("reset", &Cells4_t::reset);


        // def isActive(self, cellIdx, segIdx, state):
        // def getBestMatchingCellT(self, colIdx, state, minThreshold):
        // def getBestMatchingCellT1(self, colIdx, state, minThreshold):
        // def computeForwardPropagation(self, *args):
        
        // def updateInferenceState(self, activeColumns):
        // def inferPhase1(self, activeColumns, useStartCells):
        // def inferPhase2(self):
        // def inferBacktrack(self, activeColumns):
        // def updateLearningState(self, activeColumns, input):
        // def learnPhase1(self, activeColumns, readOnly):
        // def learnPhase2(self, readOnly):
        // def learnBacktrack(self):
        // def learnBacktrackFrom(self, startOffset, readOnly):
        // def _updateAvgLearnedSeqLength(self, prevSeqLength):
        // def chooseCellsToLearnFrom(self, cellIdx, segIdx, nSynToAdd, state, srcCells):
        // def getCellForNewSegment(self, colIdx):
        // def computeUpdate(self, cellIdx, segIdx, activeState, sequenceSegmentFlag, newSynapsesFlag):
        // def eraseOutSynapses(self, dstCellIdx, dstSegIdx, srcCells):
        // def processSegmentUpdates(self, input, predictedState):
        // def cleanUpdatesList(self, cellIdx, segIdx):
        // def applyGlobalDecay(self):
        // def _generateListsOfSynapsesToAdjustForAdaptSegment(segment, synapsesSet, inactiveSrcCellIdxs, inactiveSynapseIdxs, activeSrcCellIdxs, activeSynapseIdxs):
        // _generateListsOfSynapsesToAdjustForAdaptSegment = staticmethod(_generateListsOfSynapsesToAdjustForAdaptSegment)
        // def adaptSegment(self, update):
        // def trimSegments(self, minPermanence, minNumSyns):
        // def persistentSize(self):
        // def write(self, *args):
        // def read(self, *args):
        
        // def saveToFile(self, filePath):
        py_cells4.def("saveToFile", &Cells4_t::saveToFile);
        
        // def loadFromFile(self, filePath):
        py_cells4.def("loadFromFile", &Cells4_t::loadFromFile);

        // def save(self, outStream):
        // def load(self, inStream):

        // def setCellSegmentOrder(self, matchPythonOrder):
        py_cells4.def("setCellSegmentOrder", &Cells4_t::setCellSegmentOrder);

        // def addNewSegment(self, colIdx, cellIdxInCol, sequenceSegmentFlag, extSynapses):
        py_cells4.def("addNewSegment", &Cells4_t::addNewSegment);

        // def updateSegment(self, colIdx, cellIdxInCol, segIdx, extSynapses):
        py_cells4.def("updateSegment", &Cells4_t::updateSegment);
        
        // def _rebalance(self):
        
        // def rebuildOutSynapses(self):
        py_cells4.def("rebuildOutSynapses", &Cells4_t::rebuildOutSynapses);

        // def trimOldSegments(self, age):
        // def printStates(self):
        // def printState(self, state):
        // def dumpPrevPatterns(self, patterns):
        // def dumpSegmentUpdates(self):
        // def getNonEmptySegList(self, colIdx, cellIdxInCol):
        // def dumpTiming(self):
        // def resetTimers(self):
        // def invariants(self, verbose=False):
        // def stats(self):

        // def __init__(self, *args, **kwargs):
        //   self.this = _ALGORITHMS.new_Cells4(*args, **kwargs)
        // 
        //   self.this = _ALGORITHMS.new_Cells4()
        //   self.loadFromString(inString)
        // 
        // def read(cls, proto):
        // 
        // def write(self, pyBuilder):
        //   """Serialize the Cells4 instance using capnp.
        // 
        // def _writeAsCapnpPyBytes(self):
        // def _initFromCapnpPyBytes(self, pyBytes):

        // def loadFromString(self, inString):
        py_cells4.def("loadFromString", [](Cells4_t& self, const std::string& inString)
        {
            std::istringstream inStream(inString);
            self.load(inStream);
        });

        // def setStatePointers(self, *args):
        py_cells4.def("setStatePointers", [](Cells4_t& self
            , py::array_t<nupic::Byte>& py_infActiveStateT
            , py::array_t<nupic::Byte>& py_infActiveStateT1
            , py::array_t<nupic::Byte>& py_infPredictedStateT
            , py::array_t<nupic::Byte>& py_infPredictedStateT1
            , py::array_t<nupic::Real32>& py_colConfidenceT
            , py::array_t<nupic::Real32>& py_colConfidenceT1
            , py::array_t<nupic::Real32>& py_cellConfidenceT
            , py::array_t<nupic::Real32>& py_cellConfidenceT1
            )
        {
            self.setStatePointers((nupic::Byte*)get_it(py_infActiveStateT)
                , (nupic::Byte*)get_it(py_infActiveStateT1)
                , (nupic::Byte*)get_it(py_infPredictedStateT)
                , (nupic::Byte*)get_it(py_infPredictedStateT1)
                , (nupic::Real32*)get_it(py_colConfidenceT)
                , (nupic::Real32*)get_it(py_colConfidenceT1)
                , (nupic::Real32*)get_it(py_cellConfidenceT)
                , (nupic::Real32*)get_it(py_cellConfidenceT1)
            );
        });

        py_cells4.def("setStatePointers", [](const Cells4_t& self)
        {
            nupic::UInt32 nCells = self.nCells();
            nupic::UInt32 nColumns = self.nColumns();

            nupic::Byte* cpp_activeT, *cpp_activeT1;
            nupic::Byte* cpp_predT, *cpp_predT1;
            nupic::Real* cpp_colConfidenceT, *cpp_colConfidenceT1;
            nupic::Real* cpp_confidenceT, *cpp_confidenceT1;

            self.getStatePointers(cpp_activeT, cpp_activeT1,
                cpp_predT, cpp_predT1,
                cpp_colConfidenceT, cpp_colConfidenceT1,
                cpp_confidenceT, cpp_confidenceT1);

            return py::make_tuple(
                py::array_t<nupic::UInt32>({ nCells }, (nupic::UInt32*) cpp_activeT)
                , py::array_t<nupic::UInt32>({ nCells }, (nupic::UInt32*) cpp_activeT1)
                , py::array_t<nupic::UInt32>({ nCells }, (nupic::UInt32*) cpp_predT)
                , py::array_t<nupic::UInt32>({ nCells }, (nupic::UInt32*) cpp_predT1)

                , py::array_t<nupic::Real>({ nColumns }, cpp_colConfidenceT)
                , py::array_t<nupic::Real>({ nColumns }, cpp_colConfidenceT1)
                , py::array_t<nupic::Real>({ nColumns }, cpp_confidenceT)
                , py::array_t<nupic::Real>({ nColumns }, cpp_confidenceT1)
            );
        });



        // def getStates(self):
        py_cells4.def("getStates", [](const Cells4_t& self)
        {
            nupic::UInt32 nCells = self.nCells();
            nupic::UInt32 nColumns = self.nColumns();

            nupic::Byte* cpp_activeT, *cpp_activeT1;
            nupic::Byte* cpp_predT, *cpp_predT1;
            nupic::Real* cpp_colConfidenceT, *cpp_colConfidenceT1;
            nupic::Real* cpp_confidenceT, *cpp_confidenceT1;

            self.getStatePointers(cpp_activeT, cpp_activeT1,
                cpp_predT, cpp_predT1,
                cpp_colConfidenceT, cpp_colConfidenceT1,
                cpp_confidenceT, cpp_confidenceT1);

            return py::make_tuple(py::array_t<nupic::Byte>({ nCells }, cpp_activeT)
                , py::array_t<nupic::Byte>({ nCells }, cpp_activeT1)
                , py::array_t<nupic::Byte>({ nCells }, cpp_predT)
                , py::array_t<nupic::Byte>({ nCells }, cpp_predT1)

                , py::array_t<nupic::Real>({ nColumns }, cpp_colConfidenceT)
                , py::array_t<nupic::Real>({ nColumns }, cpp_colConfidenceT1)
                , py::array_t<nupic::Real>({ nColumns }, cpp_confidenceT)
                , py::array_t<nupic::Real>({ nColumns }, cpp_confidenceT1)
                );

        });

        // def getLearnStates(self):
        py_cells4.def("getLearnStates", [](const Cells4_t& self)
        {
            nupic::UInt32 nCells = self.nCells();

            nupic::Byte* cpp_activeT, *cpp_activeT1;
            nupic::Byte* cpp_predT, *cpp_predT1;

            self.getLearnStatePointers(cpp_activeT, cpp_activeT1, cpp_predT, cpp_predT1);


            return py::make_tuple(py::array_t<nupic::Byte>({ nCells }, cpp_activeT)
                , py::array_t<nupic::Byte>({ nCells }, cpp_activeT1)
                , py::array_t<nupic::Byte>({ nCells }, cpp_predT)
                , py::array_t<nupic::Byte>({ nCells }, cpp_predT1)
            );
        });


        // def compute(self, *args):
        py_cells4.def("compute", [](Cells4_t& self, py::array_t<nupic::Real> x, bool doInference, bool doLearning)
        {
            py::array_t<nupic::Real> y(self.nCells());

            self.compute(get_it(x), get_it(y), doInference, doLearning);

            return y;
        });

        // _MAX_CELLS = cvar._MAX_CELLS
        // _MAX_SEGS = cvar._MAX_SEGS

        //def Cells4__generateListsOfSynapsesToAdjustForAdaptSegment(segment, synapsesSet, inactiveSrcCellIdxs, inactiveSynapseIdxs, activeSrcCellIdxs, activeSynapseIdxs):

        /////////////////

        // def __setstate__(self, inString):
        // def __getstate__(self):
        py_cells4.def(py::pickle(
            [](const Cells4_t& self) -> std::string
        {
            // __getstate__
            std::ostringstream os;
            self.save(os);

            return os.str();
        },
            [](const std::string& str) -> Cells4_t
        {
            // __setstate__
            if (str.empty())
            {
                throw std::runtime_error("Empty state");
            }

            std::istringstream is(str);

            Cells4_t a;
            a.load(is);

            return a;
        }
        ));
    }

} // namespace nupix_ext
