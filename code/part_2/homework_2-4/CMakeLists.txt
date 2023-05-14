# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(homework_2_4 VERSION 1.0 LANGUAGES CXX)

# define the c++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

# add a library for your student structure
add_library(hw24_animals src/animals.cpp)
# add the includes to the library
target_include_directories(hw24_animals PUBLIC include)

# add an executabel and assign files to it
add_executable(hw24_animals_exec src/main.cpp)

# add include directories to executable
target_include_directories(hw24_animals_exec PRIVATE include)
# link your libraries
target_link_libraries(hw24_animals_exec PRIVATE hw24_animals)

enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(hw24_animals_tests test/test_animals.cpp)
# link the gtest libraries
target_link_libraries(hw24_animals_tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(hw24_animals_tests PRIVATE hw24_animals)
# add the include directories
target_include_directories(hw24_animals_tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(hw24_animals_tests)
