# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(libraries VERSION 1.0 LANGUAGES C)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add a library for your functions
add_library(libraries_ex_func_lib STATIC src/functions.c)
# add the includes to the library
target_include_directories(libraries_ex_func_lib PUBLIC include)

# add a library for your prints
add_library(libraries_ex_print_lib SHARED src/prints.c)
# add the includes to the library
target_include_directories(libraries_ex_print_lib PUBLIC include)

# add an executabel and assign files to it
add_executable(libraries_ex_exec src/main.c)
# add the include directories
target_include_directories(libraries_ex_exec PUBLIC include)
# link your libraries
target_link_libraries(libraries_ex_exec PRIVATE 
    libraries_ex_func_lib 
    libraries_ex_print_lib)
