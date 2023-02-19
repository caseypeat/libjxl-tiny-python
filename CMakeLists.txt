
cmake_minimum_required(VERSION 3.10)

project(jxlbinding)

add_subdirectory(libjxl-tiny)
add_subdirectory(pybind11)

pybind11_add_module(jxlbinding jxlbinding.cc)

target_link_libraries(jxlbinding PUBLIC jxl_tiny)