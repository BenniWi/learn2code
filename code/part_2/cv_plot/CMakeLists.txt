# define the minimum cmake version
cmake_minimum_required(VERSION 3.20)

# define the project name
project(cv_plot_basics VERSION 1.0 LANGUAGES CXX)

# define the c standard version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add some compile options
#add_compile_options(-Wall -Wextra -pedantic -O0)
add_compile_options(-Wall)

# search for module opencv
find_package( OpenCV ) # alternative: find_package( OpenCV REQUIRED )

# continue only if opencv is found
if(OpenCV_FOUND)
    # enable FetchContent module
    include(FetchContent)

    # download CvPlot library and add it to the project
    FetchContent_Declare(cvplot
        GIT_REPOSITORY https://github.com/Profactor/cv-plot.git
        GIT_TAG origin/master) # or whatever tag you want
    FetchContent_GetProperties(cvplot)
    if(NOT cvplot_POPULATED)
        set(CVPLOT_USE_CONAN FALSE)
        FetchContent_Populate(cvplot)
    endif()

    # download rapidcsv library and add it to the project
    FetchContent_Declare(rapidcsv
        GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
        GIT_TAG origin/master) # or whatever tag you want
    FetchContent_MakeAvailable(rapidcsv)

    # download armadillo library and add it to the project
    FetchContent_Declare(armadillo
        URL https://sourceforge.net/projects/arma/files/armadillo-12.4.0.tar.xz)
    FetchContent_MakeAvailable(armadillo)

    # add executable for cvplot hello world
    add_executable(cvplot_hello src/hello_world.cpp)
    target_include_directories(cvplot_hello PUBLIC ${OpenCV_INCLUDE_DIRS} ${cvplot_SOURCE_DIR}/CvPlot/inc)
    target_link_libraries( cvplot_hello ${OpenCV_LIBRARIES})

    # add executable for csv reader 
    add_executable(read_csv src/read_csv.cpp)
    target_compile_definitions(read_csv PRIVATE RESOURCEPATH="${CMAKE_CURRENT_LIST_DIR}/resources")
    target_link_libraries(read_csv PUBLIC rapidcsv)

    # add executable for weather analysis
    add_executable(weather_analysis src/weather_analysis.cpp)
    target_compile_definitions(weather_analysis PRIVATE RESOURCEPATH="${CMAKE_CURRENT_LIST_DIR}/resources")
    target_include_directories(weather_analysis PUBLIC ${OpenCV_INCLUDE_DIRS} ${cvplot_SOURCE_DIR}/CvPlot/inc)
    target_link_libraries(weather_analysis rapidcsv ${OpenCV_LIBRARIES} )

    # add executable for uncertainty ellipse
    add_executable(uncertainty_ellipse src/uncertainty_ellipse.cpp)
    target_compile_definitions(uncertainty_ellipse PRIVATE RESOURCEPATH="${CMAKE_CURRENT_LIST_DIR}/resources")
    target_include_directories(uncertainty_ellipse PUBLIC 
        ${OpenCV_INCLUDE_DIRS} 
        ${cvplot_SOURCE_DIR}/CvPlot/inc
        ${armadillo_SOURCE_DIR}/include)
    target_link_libraries(uncertainty_ellipse rapidcsv ${OpenCV_LIBRARIES} armadillo)

endif()



