cmake_minimum_required(VERSION 2.8.12)
project(python_consumer_cpp)

add_subdirectory(pybind11)
pybind11_add_module(python_consumer_cpp src/main.cpp)
