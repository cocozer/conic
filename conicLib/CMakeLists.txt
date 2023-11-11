cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(conicLib LANGUAGES C CXX)

# automatic get all files in a directory
file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.hpp)

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

# Instructions to compile a library (no main() inside)
# default STATIC ??
# SHARED to make a .so instead of a .a
# add_library(ganQ SHARED ${source_files} ${header_files})
add_library(conicLib ${source_files} ${header_files})

# compilation flags
target_compile_features(conicLib PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(conicLib PRIVATE /W3)
else()
    target_compile_options(conicLib PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# include directory
target_include_directories(conicLib PRIVATE "include")
target_include_directories(conicLib PRIVATE "${EIGEN3_INCLUDE_DIR}")


# install (optional, install a lib is not mandatory)
install(FILES ${header_files} DESTINATION /usr/local/include/conicLib)
install(TARGETS conicLib
        RUNTIME DESTINATION /usr/local/lib
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION /usr/local/lib)


