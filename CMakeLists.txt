cmake_minimum_required(VERSION 3.20)

project(learn2code LANGUAGES C CXX)

set(BUILD_PART_1 ON, CACHE BOOL "Enable building code of part 1")
set(BUILD_PART_2 ON, CACHE BOOL "Enable building code of part 2")

if(BUILD_PART_1)
    # add the C projects
    add_subdirectory(./code/part_1/basics)
    add_subdirectory(./code/part_1/basics_in_C)
    add_subdirectory(./code/part_1/cmake)
    add_subdirectory(./code/part_1/const_correctness)
    add_subdirectory(./code/part_1/debugging)
    add_subdirectory(./code/part_1/functions)
    add_subdirectory(./code/part_1/libraries)
    add_subdirectory(./code/part_1/user_input)
    # add the C homeworks
    add_subdirectory(./code/part_1/homework_1-2)
    add_subdirectory(./code/part_1/homework_1-3)
    add_subdirectory(./code/part_1/homework_1-4)
    add_subdirectory(./code/part_1/homework_1-5)
    add_subdirectory(./code/part_1/homework_1-6)
    add_subdirectory(./code/part_1/homework_1-7)
endif()


if(BUILD_PART_2)
    # add the C++ projects
    add_subdirectory(./code/part_2/basics_in_Cpp)
    add_subdirectory(./code/part_2/tdd)
    add_subdirectory(./code/part_2/opencv_basics)
    add_subdirectory(./code/part_2/cv_plot)
    # add the C++ homeworks
    add_subdirectory(./code/part_2/homework_2-3)
    add_subdirectory(./code/part_2/homework_2-4)
endif()