#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/math/SparseMatrixConnections.hpp>

#include "py_utils.hpp"

namespace py = pybind11;

namespace nupic_ext
{
    void init_SMC(py::module& m)
    {
        typedef nupic::SparseMatrixConnections SMC_t;

        py::class_<SMC_t> smc(m, "SparseMatrixConnections");

        smc.def(py::init<nupic::UInt32, nupic::UInt32>(), py::arg("numCells"), py::arg("numInputs"));


        smc.def("adjustSynapses", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , nupic::Real32 activePermanenceDelta, nupic::Real32 inactivePermanenceDelta)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            smc.adjustSynapses(get_it(segments), get_end(segments)
                , get_it(activeInputs), get_end(activeInputs)
                , activePermanenceDelta, inactivePermanenceDelta);
        });

        smc.def("adjustActiveSynapses", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , nupic::Real32 permanenceDelta)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            smc.adjustActiveSynapses(get_it(segments), get_end(segments)
                , get_it(activeInputs), get_end(activeInputs)
                , permanenceDelta);
        });

        smc.def("adjustInactiveSynapses", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , nupic::Real32 permanenceDelta)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            smc.adjustInactiveSynapses(get_it(segments), get_end(segments)
                , get_it(activeInputs), get_end(activeInputs)
                , permanenceDelta);
        });

        smc.def("clipPermanences", [](SMC_t& smc, py::array_t<nupic::UInt32>& segments) 
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            
            smc.clipPermanences(get_it(segments), get_end(segments));
        });



        smc.def("computeActivity", [](SMC_t& smc, py::array_t<nupic::UInt32>& activeInputs)
        {
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            py::array_t<nupic::Int32> out(smc.matrix.nRows());

            smc.computeActivity(get_it(activeInputs), get_end(activeInputs), get_it(out));

            return out;
        });

        smc.def("computeActivity", [](SMC_t& smc, py::array_t<nupic::UInt32>& activeInputs, nupic::Real32 permanenceThreshold)
        {
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            py::array_t<nupic::Int32> out(smc.matrix.nRows());

            smc.computeActivity(get_it(activeInputs), get_end(activeInputs), permanenceThreshold, get_it(out));

            return out;
        });


        smc.def("computeActivity", [](SMC_t& smc, py::array_t<nupic::UInt32>& activeInputs, py::array_t<nupic::Int32>& overlaps)
        {
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (overlaps.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            smc.computeActivity(get_it(activeInputs), get_end(activeInputs), get_it(overlaps));
        });

        smc.def("createSegments", [](SMC_t& smc, py::array_t<nupic::UInt32>& cells)
        {
            if (cells.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            py::array_t<nupic::UInt32> segmentsOut(cells.size());
            smc.createSegments(get_it(cells), get_end(cells), get_it(segmentsOut));

            return segmentsOut;
        });


        smc.def("growSynapses", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , nupic::Real32 initialPermanence)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            smc.growSynapses(get_it(segments), get_end(segments)
                , get_it(activeInputs), get_end(activeInputs)
                , initialPermanence);
        });


        smc.def("growSynapsesToSample", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , nupic::Int32 sampleSize
            , nupic::Real32 initialPermanence
            , nupic::Random& rng
            , bool assumeInputsSorted)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            if (assumeInputsSorted)
            {
                smc.growSynapsesToSample(get_it(segments), get_end(segments)
                    , get_it(activeInputs), get_end(activeInputs)
                    , sampleSize, initialPermanence, rng);
            }
            else
            {
                if (activeInputs.size() > 0)
                {
                    std::vector<nupic::UInt32> sorted(get_it(activeInputs), get_end(activeInputs));
                    std::sort(sorted.begin(), sorted.end());

                    auto sorted_it = sorted.data();
                    auto sorted_end = sorted_it + sorted.size();

                    smc.growSynapsesToSample(get_it(segments), get_end(segments)
                        , sorted_it, sorted_end
                        , sampleSize, initialPermanence, rng);
                }
                else
                {
                    throw std::runtime_error("Input cannot be empty.");
                }
            }


        }, "", py::arg("segments"), py::arg("activeInputs"), py::arg("sampleSize"), py::arg("initialPermanence"), py::arg("rng"), py::arg("assumeInputsSorted") = false);

        smc.def("growSynapsesToSample", [](SMC_t& smc
            , py::array_t<nupic::UInt32>& segments
            , py::array_t<nupic::UInt32>& activeInputs
            , py::array_t<nupic::Int32>& sampleSize
            , nupic::Real32 initialPermanence
            , nupic::Random& rng
            , bool assumeInputsSorted)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (activeInputs.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }
            if (sampleSize.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            if (assumeInputsSorted)
            {
                smc.growSynapsesToSample(get_it(segments), get_end(segments)
                    , get_it(activeInputs), get_end(activeInputs)
                    , get_it(sampleSize), get_end(sampleSize)
                    , initialPermanence, rng);
            }
            else
            {
                if (activeInputs.size() > 0)
                {
                    std::vector<nupic::UInt32> sorted(get_it(activeInputs), get_end(activeInputs));
                    std::sort(sorted.begin(), sorted.end());

                    auto sorted_it = sorted.data();
                    auto sorted_end = sorted_it + sorted.size();

                    smc.growSynapsesToSample(get_it(segments), get_end(segments)
                        , sorted_it, sorted_end
                        , get_it(sampleSize), get_end(sampleSize)
                        , initialPermanence, rng);
                }
                else
                {
                    throw std::runtime_error("Input cannot be empty.");
                }
            }


        }, "", py::arg("segments"), py::arg("activeInputs"), py::arg("sampleSize"), py::arg("initialPermanence"), py::arg("rng"), py::arg("assumeInputsSorted") = false);



        smc.def("mapSegmentsToSynapseCounts", [](SMC_t& smc, py::array_t<nupic::UInt32>& segments)
        {
            if (segments.ndim() != 1) { throw std::runtime_error("Number of dimensions must be one."); }

            py::array_t<nupic::Int32> out(segments.size());
            smc.mapSegmentsToSynapseCounts(get_it(segments), get_end(segments), get_it(out));

            return out;
        });

    }
} // namespace nupix_ext
