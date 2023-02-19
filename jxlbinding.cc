#include <stdio.h>
#include <errno.h>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <Python.h>

#include "libjxl-tiny/encoder/base/printf_macros.h"
#include "libjxl-tiny/encoder/enc_file.h"
#include "libjxl-tiny/encoder/image.h"
#include "libjxl-tiny/encoder/read_pfm.h"
#include "libjxl-tiny/encoder/base/byte_order.h"

namespace py = pybind11;


void numpy_to_image3f(py::array_t<float, py::array::c_style> array_np, jxl::Image3F* image) {

    const float* input = reinterpret_cast<const float*>(array_np.data());
    const size_t stride = image->xsize() * 3;
    for (size_t y = 0; y < image->ysize(); ++y) {
        size_t y_in = image->ysize() - 1 - y;
        const float* row_in = &input[y_in * stride];
        for (size_t c = 0; c < 3; ++c) {
            float* row_out = image->PlaneRow(c, y);
            for (size_t x = 0; x < image->xsize(); ++x) {
                row_out[x] = row_in[x * 3 + c];
            }
        }
    }
    return;
}



py::array_t<uint8_t, py::array::c_style> encode_image(py::array_t<float, py::array::c_style> input_np) {
    
    jxl::Image3F image(input_np.shape()[1], input_np.shape()[0]);

    numpy_to_image3f(input_np, &image);

    std::vector<uint8_t> output;
    jxl::EncodeFile(image, 1.0, &output);

    py::array_t<uint8_t, py::array::c_style> output_np = py::cast(output);

    return output_np;
}

PYBIND11_MODULE(jxlbinding, m) {
    m.doc() = "jxl binding"; // optional module docstring

    m.def("encode_image", &encode_image, "save jxl image");
}