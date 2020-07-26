cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME Main)

project(${PROJECT_NAME})

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE Main_src src/*.cpp)
file(GLOB_RECURSE Main_inc include/*.h)
include_directories("include")

if(WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
endif()

add_executable(${PROJECT_NAME}  ${Main_src}
                                ${Main_inc})

target_link_libraries(${PROJECT_NAME} DKCore)
target_link_libraries(${PROJECT_NAME} DKGui)
include_directories("../gui/include")
include_directories("../core/include")
