cmake_minimum_required(VERSION 3.16)

project(lab6 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
    main.cpp
    Employee.cpp
    Salaried.cpp
    Commission.cpp
    Hourly.cpp
)
