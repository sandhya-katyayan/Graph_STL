# 🌐 Graph Algorithm Driver Program in C++

This project is a **comprehensive C++ driver program** designed to test and demonstrate a wide range of graph algorithms, including traversal, cycle detection, bipartite checking, topological sorting, and shortest path algorithms. All functionalities are built using a custom `Graph` class in `Graph.hpp`.

---

## 📌 Features

This program supports the following graph functionalities:

### 🔁 Graph Traversal
- Breadth-First Search (BFS)
- Depth-First Search (DFS)

### ⚠️ Cycle Detection
- In Undirected Graphs (using BFS & DFS)
- In Directed Graphs (using DFS)

### 🎨 Bipartite Graph Check
- Using BFS

### 📊 Topological Sorting
- DFS-based topological sort
- BFS-based (Kahn’s Algorithm)

### 📉 Shortest Path Algorithms
- Shortest Path in DAG (using Topological Sort)
- Dijkstra’s Algorithm (Weighted Graphs, no negative weights)
- Bellman-Ford Algorithm (Handles negative weights)

---

## 📁 File Structure

.
├── main.cpp # Driver code for input & testing
├── Graph.hpp # Header file with Graph class and all algorithms


🧪 Sample Input to Test
➤ Part 1: Basic Graph with Directed Edges
Enter the number of vertex and edges in the graph: 
5 6
0 1 1
0 2 1
1 3 1
2 3 1
2 4 1
3 4 1

➤ Part 2: Weighted DAG for Shortest Paths
Emter the number of vertex and edges in the DAG:
5 6
0 1 2
0 2 4
1 3 1
2 3 2
2 4 3
3 4 2

➤ Part 3: Repeat for Bellman-Ford
0 1 2
0 2 4
1 3 1
2 3 2
2 4 3
3 4 2

✅ Expected Output (Abbreviated)
Printing the adjacency list of the graph:
0 -> 1 , 2 , 
1 -> 3 , 
2 -> 3 , 4 , 
3 -> 4 , 
4 ->

BFS traversal of the graph is:
0 1 2 3 4

DFS traversal of the graph is:
0 1 3 4 2

Cycle detection in undirected graph using BFS:
Cycle is not present in the graph

Cycle detection in undirected graph using DFS:
Cycle is not present in the graph

Checking whether the graph is bipartite using BFS:
Graph is bipartite

Cycle detection in directed graph using DFS:
Cycle is not present in the graph

Topological sort of the graph using DFS:
0 2 1 3 4

Topological sort of the graph using BFS:
0 1 2 3 4

Shortest path in directed acyclic graph using topological sort:
0 2 4 3 5

Shortest path in weighted graph using Dijkstra’s algorithm:
0 2 4 3 5

Shortest path in weighted graph using Bellman-Ford algorithm:
0 2 4 3 5

🚀 What You’ll Learn
Practical implementation of real-world graph algorithms

Clean graph class design using STL (unordered_map, list, vector)

Edge cases for directed vs undirected, weighted vs unweighted graphs

Integration of algorithms like Dijkstra, Bellman-Ford, Kahn’s Topo Sort, and more

👩‍💻 Author
Sandhya Kumari
📧 sandhyakumari0293@gmail.com
🔗 GitHub
🔗 Portfolio
🔗 LinkedIn

🌟 Like this repo?
If this helped you, give it a star ⭐ on GitHub to support the project!
