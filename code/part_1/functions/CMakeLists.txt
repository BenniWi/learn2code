# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(functions_operators VERSION 1.0 LANGUAGES C)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add an executabel and assign files to it
add_executable(functions_ex_spaghetti src/main_spaghetti.c)
# add an executabel and assign files to it
add_executable(functions_ex_w_function src/main_w_function.c)
# add an executabel and assign files to it
add_executable(functions_ex_w_prototype src/main_w_prototype.c)
# add an executabel and assign files to it
add_executable(functions_ex_w_sep_files src/main_w_sep_files.c src/functions.c)
# add the include directories
target_include_directories(functions_ex_w_sep_files PUBLIC include)
