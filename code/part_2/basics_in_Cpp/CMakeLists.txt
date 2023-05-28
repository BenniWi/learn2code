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
add_executable(pointer_vs_reference pointer_vs_reference.cpp)
add_executable(namespace namespace.cpp)
add_executable(inheritance inheritance.cpp)
add_executable(multi_inheritance multi_inheritance.cpp)
add_executable(polymorphism polymorphism.cpp)
add_executable(polymorphism_exercise polymorphism_exercise.cpp)
add_executable(dynamic_memory_in_c dynamic_memory.c)
add_executable(dynamic_memory_in_cpp_old dynamic_memory_old.cpp)
add_executable(dynamic_memory_in_cpp_new dynamic_memory_new.cpp)
add_executable(static_keyword static_keyword.cpp)
add_executable(type_casting type_casting.cpp)
add_executable(templates templates.cpp)
add_executable(stl stl.cpp)
add_executable(stl_and_casting_exercise stl_and_casting_exercise.cpp)
add_executable(exceptions exceptions.cpp)