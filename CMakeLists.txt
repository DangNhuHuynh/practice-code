cmake_minimum_required(VERSION 3.5.0)
project(practice-code)

# Set compiler
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# Include all source C
file(GLOB_RECURSE SOURCE_C
        C/*
    )

# Include all source C++
file(GLOB_RECURSE SOURCE_CXX
        C++/*
    )

# Include all source test
file(GLOB_RECURSE SOURCE_TEST
        test/*
    )

file(GLOB_RECURSE STRING_TEST
        test/String.cpp
        C++/String/String.cpp
    )

add_executable(all_test ${SOURCE_TEST} ${SOURCE_C} ${SOURCE_CXX} misc/main-test.cpp C++/String/String.hpp C++/String/String.cpp test/String.cpp)
add_executable(string_test ${STRING_TEST} misc/main-test.cpp)