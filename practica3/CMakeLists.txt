cmake_minimum_required (VERSION 3.1)
project (practica3)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
add_executable(test src/test.cpp src/graph.hpp src/graph_utils.hpp src/city.hpp src/city.cpp)
