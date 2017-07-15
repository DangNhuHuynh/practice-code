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

add_executable(all_test ${SOURCE_TEST} ${SOURCE_C} ${SOURCE_CXX} misc/main-test.cpp)
