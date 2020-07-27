cmake_minimum_required(VERSION 3.10)

project(Main)

file(GLOB_RECURSE Main_src src/*.cpp)
file(GLOB_RECURSE Main_inc include/*.h)

if (WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
endif ()

add_executable(${PROJECT_NAME}
        ${Main_src}
        ${Main_inc}
        )

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        DKCore
        DKGui
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        include
        )
