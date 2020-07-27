cmake_minimum_required(VERSION 3.10)

project(DKGui)

#Instruct Cmake to run moc, uic and rcc automatically when nedded.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

file(GLOB_RECURSE Gui_src src/*.cpp)
file(GLOB_RECURSE Gui_ui src/*.ui)
file(GLOB_RECURSE Gui_include include/*.h)

add_library(${PROJECT_NAME}
        STATIC
        ${Gui_src}
        ${Gui_include}
        ${Gui_ui}
        )

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Widgets
        PRIVATE
        DKCore
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        include
        )

if (MSVC)
    get_filename_component(QT5_BINARY_DIR ${QT_MOC_EXECUTABLE} DIRECTORY)
    set(DEBUG_PATH_SETTINGS "${QT5_BINARY_DIR};")
    CONFIGURE_FILE(vsprops.user "DKGui.vcxproj.user" @ONLY)
endif ()