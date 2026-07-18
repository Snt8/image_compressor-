cmake_minimum_required(VERSION 4.1)
project(image_compressor CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(image_compressor
        src/core/compressor.c
        src/core/compressor.h
        src/processor/image_processor.cpp
        src/processor/image_processor.hpp
        src/main.cpp)

target_include_directories(image_compressor PRIVATE
        src/core
        src/processor
        ui/include
)
