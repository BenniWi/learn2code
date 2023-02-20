# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(basics_in_C VERSION 1.0 LANGUAGES C)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

# add an executabel and assign files to it
add_executable(c_arrays basics_in_c_arrays.c)
add_executable(branching_and_looping basics_in_c_branching_looping.c)
add_executable(macro basics_in_c_macro.c)
add_executable(pointers basics_in_c_pointers.c)
add_executable(structures basics_in_c_structures.c)
add_executable(variables basics_in_c_variables.c)
add_executable(basics_in_c basics_in_c.c)
