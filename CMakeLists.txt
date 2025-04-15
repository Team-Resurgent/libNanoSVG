cmake_minimum_required(VERSION 3.25)
project(NanoSVG)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
endif()

include_directories(nanosvg)

add_library(NanoSVG SHARED main.cpp)
