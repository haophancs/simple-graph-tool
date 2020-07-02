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
        widgets/sources/GraphMatrixTable.cpp
        widgets/headers/GraphMatrixTable.h
        basis/sources/GraphUtils.cpp
        basis/headers/GraphUtils.h
        widgets/sources/InputDialog.cpp
        widgets/headers/InputDialog.h
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
        widgets/headers/ElementPropertiesTable.h widgets/sources/GraphPropertiesTable.cpp widgets/headers/GraphPropertiesTable.h basis/headers/Matrix.h basis/headers/Edge.h widgets/headers/OptionDialog.h widgets/sources/OptionDialog.cpp) #sources/Edge.cpp utils/Edge.h)

target_link_libraries(simple_graph_tool Qt5::Core)
target_link_libraries(simple_graph_tool Qt5::Widgets)
target_link_libraries(simple_graph_tool Qt5::Gui)