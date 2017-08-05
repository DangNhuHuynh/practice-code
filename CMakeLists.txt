cmake_minimum_required(VERSION 3.2.2)
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
        test/StringTest.cpp
        C++/String/String.cpp
    )

add_executable(string_test ${STRING_TEST} misc/main-test.cpp)