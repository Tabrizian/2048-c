cmake_minimum_required(VERSION 2.8.8)

project(2048 C)

add_subdirectory(src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
