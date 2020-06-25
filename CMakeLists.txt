cmake_minimum_required(VERSION 3.0.0)
project(simple_graph_tool VERSION 0.1 LANGUAGES CXX)

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
        sources/ArcGraphicsItem.cpp
        headers/ArcGraphicsItem.h
        sources/Graph.cpp
        headers/Graph.h
        sources/GraphGraphicsScene.cpp
        headers/GraphGraphicsScene.h
        sources/GraphGraphicsView.cpp
        headers/GraphGraphicsView.h
        sources/GraphMatrixTable.cpp
        headers/GraphMatrixTable.h
        sources/GraphUtils.cpp
        headers/GraphUtils.h
        sources/InputDialog.cpp
        headers/InputDialog.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        sources/Node.cpp
        headers/Node.h
        sources/NodeGraphicsItem.cpp
        headers/NodeGraphicsItem.h
        headers/qdebugstream.h
        headers/random.h
        sources/ElementPropertiesTable.cpp
        headers/ElementPropertiesTable.h)

target_link_libraries(simple_graph_tool Qt5::Core)
target_link_libraries(simple_graph_tool Qt5::Widgets)
target_link_libraries(simple_graph_tool Qt5::Gui)