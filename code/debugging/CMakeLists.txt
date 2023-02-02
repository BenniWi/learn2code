# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(debugging VERSION 1.0 LANGUAGES C CXX)

# define the c standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# define the c++ standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
add_compile_options(-Wall -Wextra -Werror -pedantic -O0)

# add a library for your functions
add_library(functions_lib STATIC src/functions.c)
# add the includes to the library
target_include_directories(functions_lib PUBLIC include)

# add an executabel and assign files to it
add_executable(debugging_ex_exec src/main.c)
# add the include directories
target_include_directories(debugging_ex_exec PUBLIC include)
# link your library
target_link_libraries(debugging_ex_exec PRIVATE functions_lib)


# enable the testing
enable_testing()
# check if we have gtest
find_package(GTest REQUIRED)
# include the gtest CMake stuff
include(GoogleTest)
# create a test executable
add_executable(tests test/test_functions.cpp)
# link the gtest libraries
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main)
# link the library we want to test
target_link_libraries(tests PRIVATE functions_lib)
# add the inlucde direactores
target_include_directories(tests PUBLIC include)
# discover and add tests to the test list
gtest_discover_tests(tests)
