cmake_minimum_required(VERSION 3.15)


# give a name to the project
project(conic LANGUAGES C CXX)

# include Eigen
find_package(Eigen3)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    set(EIGEN3_INCLUDE_DIR "C:/eigen3") # put your path instead of "C:/eigen/eigen-3.4.0"
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
    #message(FATAL_ERROR "lib EIGEN3 not found")
endif()


# file to compile and name of the executable
add_executable(conic src/main.cpp src/Geogebra_conics.cpp include/Geogebra_conics.hpp src/Entry.cpp include/Entry.hpp src/Directory.cpp include/Directory.hpp)

# include directory
target_include_directories(conic PRIVATE "include")

target_link_libraries(conic PRIVATE conicLib)      # lib dependency

# compilation options
target_compile_features(conic PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(conic PRIVATE /W3)
else()
    target_compile_options(conic PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# lib include path
target_include_directories(conic PRIVATE "${EIGEN3_INCLUDE_DIR}")






