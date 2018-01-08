cmake_minimum_required(VERSION 3.9)
project(_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(_algorithms
        Sort/BubbleSort.h
        Sort/InsertionSort.h
        Sort/main.cpp
        Sort/MergeSort.h
        Sort/SelectionSort.h
        Sort/ShellSort.h
        Sort/SortTestHelper.h
        Sort/Student.h)
