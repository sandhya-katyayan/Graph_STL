# Graph_STL
A templated C++ Graph Library with DFS, BFS, Dijkstra, MST, Topological Sort, SCC and more.


# 🚀 Graph STL in C++

This is a lightweight and powerful **C++ Graph Library** implemented using **Templates** and **STL**. It supports:

- ✅ DFS (Depth First Search)
- ✅ BFS (Breadth First Search)
- ✅ Dijkstra’s Shortest Path
- ✅ Kruskal’s Minimum Spanning Tree
- ✅ Topological Sort
- ✅ Cycle Detection
- ✅ Strongly Connected Components (Kosaraju’s Algorithm)

---

## 📁 Files

- `graph.hpp` → Header file with all Graph functionalities
- `main.cpp` → Sample test file using the Graph STL

---

## 🧠 How to Use

### 👉 Include Header

```cpp
#include "graph.hpp"

👉 Create a Graph

Graph<int> g(n);         // n = number of vertices
Graph<int> g(n, true);   // for directed graphs

👉 Add Edges

g.add_edge(u, v);        // unweighted
g.add_edge(u, v, w);     // weighted


👉 Call Functions
g.dfs(start);             // Depth-First Search
g.bfs(start);             // Breadth-First Search
g.dijkstra(source);       // Dijkstra Shortest Path
g.kruskal_mst();          // Minimum Spanning Tree
g.topological_sort();     // Topological Ordering
g.has_cycle();            // Detect Cycles
g.scc();                  // Strongly Connected Components


🧪 Example Run
Sample run from main.cpp:
Graph<int> g(5);
g.add_edge(0, 1);
g.add_edge(1, 2);
g.add_edge(2, 3);
g.dfs(0);     // Output: 0 1 2 3


🛠️ Requirements
C++11 or above

👩‍💻 Author
Made with ❤️ by Sandhya
Feel free to contribute or report issues!
