cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME Core)

project(${PROJECT_NAME})

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE Core_src src/*.cpp)
file(GLOB_RECURSE Core_inc include/*.h)
include_directories("include")

add_library(${PROJECT_NAME} STATIC  ${Core_src}
                                    ${Core_inc})