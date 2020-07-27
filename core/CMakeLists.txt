cmake_minimum_required(VERSION 3.10)

project(DKCore)

# Instruct CMake to run moc, uic and rcc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui SerialPort)

# List of srcs
file(GLOB_RECURSE Core_src src/*.cpp)
file(GLOB_RECURSE Core_inc include/*.h)

add_library(${PROJECT_NAME}
        STATIC
        ${Core_src}
        ${Core_inc}
        )

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        include
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        PRIVATE
        Qt5::SerialPort
        )

if (MSVC)
    get_filename_component(QT5_BINARY_DIR ${QT_MOC_EXECUTABLE} DIRECTORY)
    set(DEBUG_PATH_SETTINGS "${QT5_BINARY_DIR};")
    CONFIGURE_FILE(vsprops.user "DKCore.vcxproj.user" @ONLY)
endif ()