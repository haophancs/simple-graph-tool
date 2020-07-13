# Simple Graph Tool
## Introduction 
**Simple Graph Tool** is a free tool visualizing graph theory and supporting 4 types of graph:
- Weighted - Directed Graph
- Weighted - Undirected Graph
- Unweighted - Directed Graph
- Unweighted - Undirected Graph
### Features
- **Visualization**: Providing graphical visualization for the graph. Supporting manipulation (create/edit/delete) for nodes and edge, animated demo of algorithms, displaying properties of the graph's elements
- **Matrix Views**: Displaying Adjacent matrix and Incidence matrix
### Common problems supported for demo
- BFS, DFS
- Graph coloring
- Topological Sorting algorithm
- Finding all bridges
- Finding the shortest path (Dijkstra, A*)
- Finding all articulation nodes
- Finding minimum spanning tree
- Finding independent sets of cycles
- Finding Hamiltonian cycles, Euler cycles of the graph
- Finding strongly and weakly connected components of the graph
## Building
### Dependencies
- Qt5
- CMake >= 3.0
### Linux
#### Build and run
```
git clone https://github.com/haophancs/simple-graph-tool.git
cd simple-graph-tool
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/qmake # default path: /usr/bin/qmake
make -j
./simple_graph_tool
```
## Demo Video
https://www.youtube.com/watch?v=CyHDV6y_n6s

## Detailed documentation (Vietnamese)
https://drive.google.com/file/d/13VECupgVOsi0M_QjAeuB6kN2e-Lepokq

