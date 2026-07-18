cmake_minimum_required(VERSION 4.1)
project(image_compressor C)

set(CMAKE_C_STANDARD 11)

include_directories(src/include)
include_directories(ui/include)

add_executable(image_compressor
        src/core/compressor.c
        src/include/compressor.h
        src/processor/image_processor.cpp
        src/processor/image_processor.h)
