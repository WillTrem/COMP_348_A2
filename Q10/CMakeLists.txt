cmake_minimum_required(VERSION 3.19)
project(Q10 C)

set(CMAKE_C_STANDARD 11)

add_executable(Q10 main.c)
add_library(selectionSortLib selectionsort.c selectionsort.h)

