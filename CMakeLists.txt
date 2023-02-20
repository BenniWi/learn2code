cmake_minimum_required(VERSION 3.20)

project(learn2code LANGUAGES C CXX)

# add the C projects
add_subdirectory(./code/basics)
add_subdirectory(./code/basics_in_C)
add_subdirectory(./code/cmake)
add_subdirectory(./code/const_correctness)
add_subdirectory(./code/debugging)
add_subdirectory(./code/functions)
add_subdirectory(./code/libraries)
add_subdirectory(./code/tdd)
add_subdirectory(./code/user_input)

add_subdirectory(./code/homework_1-2)
add_subdirectory(./code/homework_1-3)
add_subdirectory(./code/homework_1-4)
add_subdirectory(./code/homework_1-5)
add_subdirectory(./code/homework_1-6)
add_subdirectory(./code/homework_1-7)

# add the C++ projects
add_subdirectory(./code/basics_in_Cpp)