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
        graphics/sources/EdgeGraphicsItem.cpp
        graphics/headers/EdgeGraphicsItem.h
        basis/sources/Graph.cpp
        basis/headers/Graph.h
        graphics/sources/GraphGraphicsScene.cpp
        graphics/headers/GraphGraphicsScene.h
        graphics/sources/GraphGraphicsView.cpp
        graphics/headers/GraphGraphicsView.h
        widgets/sources/AdjacencyMatrixTable.cpp
        widgets/headers/AdjacencyMatrixTable.h
        basis/sources/GraphUtils.cpp
        basis/headers/GraphUtils.h
        widgets/sources/MultiLineInputDialog.cpp
        widgets/headers/MultiLineInputDialog.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        basis/sources/Node.cpp
        basis/headers/Node.h
        graphics/sources/NodeGraphicsItem.cpp
        graphics/headers/NodeGraphicsItem.h
        utils/qdebugstream.h
        utils/random.h
        widgets/sources/ElementPropertiesTable.cpp
        widgets/headers/ElementPropertiesTable.h
        widgets/sources/GraphPropertiesTable.cpp
        widgets/headers/GraphPropertiesTable.h
        basis/headers/Matrix.h
        basis/headers/Edge.h
        widgets/headers/GraphOptionDialog.h
        widgets/sources/GraphOptionDialog.cpp
        widgets/headers/IncidenceMatrixTable.h
        widgets/sources/IncidenceMatrixTable.cpp
        widgets/sources/MultiComboboxDialog.cpp
        widgets/headers/MultiComboboxDialog.h)

target_link_libraries(simple_graph_tool Qt5::Core)
target_link_libraries(simple_graph_tool Qt5::Widgets)
target_link_libraries(simple_graph_tool Qt5::Gui)