cmake_minimum_required(VERSION 3.15)
project(BinaryInsertionSort)

set(CMAKE_CXX_STANDARD 11)

add_executable(BinaryInsertionSort BinaryInsertionSort.cpp LinkedList.cpp LinkedList.h InsertionSort.cpp)