# Simple Graph Tool
## Introduction 
**Simple Graph Tool** is a free tool visualizing graph theory and supporting weighted directed graph. Adaptation for undirected graph is currently under development
### Features
- **Visual View**: Provides graphical visualization of the graph, supports manipulation for nodes and arc, animated demo of algorithms, displays properties of each element of the graph
- **Matrix View**: Adjacent matrix representation of the graph, GUI displays properties of each arc 
- Saving graph to file
### Common problems supported for demo
- BFS, DFS
- Graph coloring
- Topo Sort algorithm
- Finding all bridges
- Finding the shortest path
- Finding all articulation nodes
- Finding minimum spanning tree
- Finding Hamiltonian cycles, and Euler cycles of the graph
- Finding strongly and weakly connected components of the graph and grouping them
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

