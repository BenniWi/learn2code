# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(homework5 VERSION 1.0 LANGUAGES C)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add an executabel and assign files to it
add_executable(dec2bin dec2bin_converter.c)

# add an executabel and assign files to it
add_executable(triangle print_triangle.c)