# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(basics_in_Cpp VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

# add an executabel and assign files to it
add_executable(hello_world_cpp hello_world.cpp)
add_executable(struct_to_class struct_to_class.cpp)
add_executable(namespace namespace.cpp)
add_executable(inheritance inheritance.cpp)
add_executable(multi_inheritance multi_inheritance.cpp)