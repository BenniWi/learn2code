# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(tdd VERSION 1.0 LANGUAGES CXX)

# define the c++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -pedantic -O0)

# add a library for your functions
# add it without SHARED/STATIC, so we can control it with
# the variable BUILD_SHARED_LIBS
add_library(tdd_functions_lib src/functions.cpp)
# add the includes to the library
target_include_directories(tdd_functions_lib PUBLIC include)

# add an executabel and assign files to it
add_executable(tdd_ex_exec src/main.cpp)
# add the include directories
target_include_directories(tdd_ex_exec PUBLIC include)
# link your library
target_link_libraries(tdd_ex_exec PRIVATE tdd_functions_lib)


# enable the testing
include(CTest)
enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(tdd_tests test/test_functions.cpp)
# link the gtest libraries
target_link_libraries(tdd_tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(tdd_tests PRIVATE tdd_functions_lib)
# add the include directories
target_include_directories(tdd_tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(tdd_tests)
