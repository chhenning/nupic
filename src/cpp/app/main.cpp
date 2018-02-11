#include <nupic/algorithms/Cells4.hpp>

using namespace nupic;
using namespace nupic::algorithms::Cells4;
using namespace std;

int main()
{
    UInt nColumns = 10;
    UInt nCellsPerCol = 1;
    UInt activationThreshold = 12;
    UInt minThreshold = 8;
    UInt newSynapseCount = 15;
    UInt segUpdateValidDuration = 1;
    Real permInitial = 0.11;
    Real permConnected = 0.5;
    Real permMax = 1.0;
    Real permDec = 0.1;
    Real permInc = 0.1;
    Real globalDecay = 0.1;
    bool doPooling = false;
    UInt seed = 42;
    bool initFromCpp = true;
    bool checkSynapseConsistency = false;

    Cells4 c(nColumns,nCellsPerCol,activationThreshold,minThreshold,newSynapseCount,segUpdateValidDuration,permInitial,
        permConnected,permMax,permDec,permInc,globalDecay,doPooling,seed,initFromCpp,checkSynapseConsistency);

    c.setVerbosity(10);
    c.setPamLength(1);
    c.setMaxAge(100000);
    c.setMaxInfBacktrack(10);
    c.setMaxLrnBacktrack(5);
    c.setMaxSeqLength(32);
    c.setMaxSegmentsPerCell(-1);
    c.setMaxSynapsesPerCell(-1);

    c.setCellSegmentOrder(true);

    vector<nupic::Real> input(10, 0.0);
    input[1] = 1.0;

    vector<nupic::Real> output(10, 0.0);

    c.compute(input.data(), output.data(), false, true);

    auto num_segments = c.nSegments();

    return 0;
}