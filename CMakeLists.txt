cmake_minimum_required(VERSION 3.22.1)

project(algorithms)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 ")

add_subdirectory(test)


add_executable(algorithms main.cpp container search sort sort/quickSort.h sort/stoogeSort.h sort/shellSort.h sort/countSort.h sort/radixSort.h utils.h container/array.h mathematical/Vector.h mathematical/Matrix.h)

