cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME DKGui)

project(${PROJECT_NAME})

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_BINARY_DIR}/lib)

#Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH Qt5)

#Instruct Cmake to run moc, uic and rcc automatically when nedded.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#Executables fail to build with Qt5 in the default configuration because the -fPIE flag is needed.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

file(GLOB_RECURSE Gui_src src/*.cpp)
file(GLOB_RECURSE Gui_ui src/*.ui)
file(GLOB_RECURSE Gui_include include/*.h)

include_directories("include")
find_package(Qt5Widgets)

add_library(${PROJECT_NAME} STATIC ${Gui_src}
                                   ${Gui_include}
                                   ${Gui_ui})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} DKCore)
include_directories("../core/include")

if(MSVC)
  get_filename_component(QT5_BINARY_DIR ${QT_MOC_EXECUTABLE} DIRECTORY)
  set(DEBUG_PATH_SETTINGS "${QT5_BINARY_DIR};")
  CONFIGURE_FILE(vsprops.user "DKGui.vcxproj.user" @ONLY)
endif()