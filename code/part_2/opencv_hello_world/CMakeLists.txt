# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(opencv_hello VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

find_package( OpenCV REQUIRED )

# add an executabel and assign files to it
add_executable(opencv_hello src/main.cpp)
# include and link all opencv stuff
target_include_directories(opencv_hello PUBLIC ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( opencv_hello ${OpenCV_LIBRARIES})