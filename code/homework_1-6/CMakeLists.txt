# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(homework51 VERSION 1.0 LANGUAGES C)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add an executabel and assign files to it
add_executable(student_struct_exec
                    src/main.c
                    src/student.c)

# add include directories to executable
target_include_directories(student_struct_exec PRIVATE include)