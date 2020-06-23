cmake_minimum_required(VERSION 3.10)
project(simple_graph_tool)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/usr/bin/qmake")

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(.)

add_executable(simple_graph_tool
        arcgraphicsitem.cpp
        arcgraphicsitem.h
        graph.cpp
        graph.h
        graphgraphicsscene.cpp
        graphgraphicsscene.h
        graphgraphicsview.cpp
        graphgraphicsview.h
        graphmatrixtable.cpp
        graphmatrixtable.h
        graphutils.cpp
        graphutils.h
        inputdialog.cpp
        inputdialog.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        node.cpp
        node.h
        nodegraphicsitem.cpp
        nodegraphicsitem.h
        qdebugstream.h)

target_link_libraries(simple_graph_tool Qt5::Core)
target_link_libraries(simple_graph_tool Qt5::Widgets)
target_link_libraries(simple_graph_tool Qt5::Gui)