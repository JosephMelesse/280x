cmake_minimum_required(VERSION 3.28.3)

project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GSL REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE GSL::gsl GSL::gslcblas)
