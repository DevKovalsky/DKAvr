cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME DKCore)

project(${PROJECT_NAME})

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE Core_src src/*.cpp)
file(GLOB_RECURSE Core_inc include/*.h)
include_directories("include")

#Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH Qt5)

# Instruct CMake to run moc, uic and rcc automatically when needed.
# This will intelegently
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#Executables fail to build with Qt5 in the default configuration because the -fPIE flag is needed.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt5Widgets)

add_library(${PROJECT_NAME} STATIC ${Core_src}
                                   ${Core_inc})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

if(MSVC)
  get_filename_component(QT5_BINARY_DIR ${QT_MOC_EXECUTABLE} DIRECTORY)
  set(DEBUG_PATH_SETTINGS "${QT5_BINARY_DIR};")
  CONFIGURE_FILE(vsprops.user "DKCore.vcxproj.user" @ONLY)
endif()