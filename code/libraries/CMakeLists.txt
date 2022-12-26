# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(libraries VERSION 1.0)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# define the c++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add a library for your functions
add_library(${PROJECT_NAME}_func_lib STATIC src/functions.c)
# add the includes to the library
target_include_directories(${PROJECT_NAME}_func_lib PUBLIC include)

# add a library for your prints
add_library(${PROJECT_NAME}_print_lib SHARED src/prints.c)
# add the includes to the library
target_include_directories(${PROJECT_NAME}_print_lib PUBLIC include)

# add an executabel and assign files to it
add_executable(${PROJECT_NAME} src/main.c)
# add the include directories
target_include_directories(${PROJECT_NAME} PUBLIC include)
# link your libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${PROJECT_NAME}_func_lib 
    ${PROJECT_NAME}_print_lib)
