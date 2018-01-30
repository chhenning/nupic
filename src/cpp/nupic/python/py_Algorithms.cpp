#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/algorithms/Segment.hpp>

#include "py_utils.hpp"

namespace py = pybind11;

namespace nupic_ext
{
    void init_algorithms(py::module& m)
    {
        typedef nupic::algorithms::Cells4::Segment Segment_t;

        m.def("getSegmentActivityLevel", [](py::list seg
            , py::array_t<nupic::Byte>& py_state
            , bool connectedSynapsesOnly
            , nupic::Real32 connectedPerm)
        {
            nupic::UInt32 activity = 0;

            auto state = get_it(py_state);
            auto stride0 = py_state.request().strides[0];

            // see algorithms.i[748]
            if (connectedSynapsesOnly)
            {
                for (py::size_t i = 0; i < seg.size(); ++i)
                {
                    py::list syn = seg[i];

                    nupic::Real32 p = syn[2].cast<nupic::Real32>();

                    if (p >= connectedPerm)
                    {
                        nupic::UInt32 c = syn[0].cast<nupic::UInt32>();
                        nupic::UInt32 j = syn[1].cast<nupic::UInt32>();

                        activity += state[c * stride0 + j];
                    }
                }
            }
            else
            {
                for (py::size_t i = 0; i < seg.size(); ++i)
                {
                    py::list syn = seg[i];

                    nupic::UInt32 c = syn[0].cast<nupic::UInt32>();
                    nupic::UInt32 j = syn[1].cast<nupic::UInt32>();

                    activity += state[c * stride0 + j];
                }
            }

            return activity;
        });

        m.def("isSegmentActive", [](py::list seg, py::array_t<nupic::Byte>& py_state,
            nupic::Real32 connectedPerm,
            nupic::UInt32 activationThreshold)
        {
            auto state = get_it(py_state);

            auto stride0 = py_state.request().strides[0];

            nupic::UInt32 activity = 0;

            nupic::UInt32 n = static_cast<nupic::UInt32>(seg.size());

            if (n < activationThreshold)
            {
                return false;
            }

            for (py::size_t i = 0; i < seg.size(); ++i)
            {
                py::list syn = seg[i];

                nupic::Real32 p = syn[2].cast<nupic::Real32>();
                if (p >= connectedPerm)
                {
                    nupic::UInt32 c = syn[0].cast<nupic::UInt32>();
                    nupic::UInt32 j = syn[1].cast<nupic::UInt32>();

                    activity += state[c * stride0 + j];
                    if (activity >= activationThreshold)
                    {
                        return true;
                    }
                }
            }

            return false;
        });


    }

} // namespace nupix_ext
