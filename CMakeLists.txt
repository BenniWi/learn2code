cmake_minimum_required(VERSION 3.20)

project(learn2code LANGUAGES C CXX)

# add the C projects
add_subdirectory(./code/part_1/basics)
add_subdirectory(./code/part_1/basics_in_C)
add_subdirectory(./code/part_1/cmake)
add_subdirectory(./code/part_1/const_correctness)
add_subdirectory(./code/part_1/debugging)
add_subdirectory(./code/part_1/functions)
add_subdirectory(./code/part_1/libraries)
add_subdirectory(./code/part_1/tdd)
add_subdirectory(./code/part_1/user_input)
# add the C homeworks
add_subdirectory(./code/part_1/homework_1-2)
add_subdirectory(./code/part_1/homework_1-3)
add_subdirectory(./code/part_1/homework_1-4)
add_subdirectory(./code/part_1/homework_1-5)
add_subdirectory(./code/part_1/homework_1-6)
add_subdirectory(./code/part_1/homework_1-7)


# add the C++ projects
add_subdirectory(./code/part_2/basics_in_Cpp)
# add the C++ homeworks