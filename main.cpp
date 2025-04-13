#include <iostream>
#include "Graph_Stl.hpp"
using namespace std;
using namespace graphstl;

int main() {
    cout << "==== UNDIRECTED GRAPH TEST ====\n";
    Graph<int> g1(7);  // 0 to 6

    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(1, 3);
    g1.add_edge(1, 4);
    g1.add_edge(2, 5);
    g1.add_edge(4, 5);
    g1.add_edge(3, 6);

    // DFS
    cout << "DFS from 0: ";
    for (int node : g1.dfs(0)) cout << node << " ";
    cout << "\n";

    // BFS
    cout << "BFS from 0: ";
    for (int node : g1.bfs(0)) cout << node << " ";
    cout << "\n";

    // Cycle detection
    cout << "Has Cycle: " << (g1.has_cycle() ? "Yes" : "No") << "\n";

    // Dijkstra
    Graph<int> g2(true); // directed weighted graph
    g2.add_edge(0, 1, 4);
    g2.add_edge(0, 2, 1);
    g2.add_edge(2, 1, 2);
    g2.add_edge(1, 3, 1);
    g2.add_edge(2, 3, 5);

    cout << "\n==== DIJKSTRA TEST ====\n";
    auto dist = g2.dijkstra(0);
    for (auto& [node, d] : dist) {
        cout << "Distance to " << node << ": " << d << "\n";
    }

    // Kruskal's MST
    cout << "\n==== KRUSKAL MST TEST ====\n";
    Graph<int> g3;
    g3.add_edge(0, 1, 10);
    g3.add_edge(0, 2, 6);
    g3.add_edge(0, 3, 5);
    g3.add_edge(1, 3, 15);
    g3.add_edge(2, 3, 4);

    auto mst = g3.kruskal_mst();
    for (auto& [w, u, v] : mst) {
        cout << u << " - " << v << " : " << w << "\n";
    }

    // Topological Sort
    cout << "\n==== TOPOLOGICAL SORT TEST ====\n";
    Graph<int> g4(true);
    g4.add_edge(5, 2);
    g4.add_edge(5, 0);
    g4.add_edge(4, 0);
    g4.add_edge(4, 1);
    g4.add_edge(2, 3);
    g4.add_edge(3, 1);

    for (int node : g4.topological_sort())
        cout << node << " ";
    cout << "\n";

    // SCC
    cout << "\n==== STRONGLY CONNECTED COMPONENTS TEST ====\n";
    Graph<int> g5(8); // Vertices 0-7
    g5.add_edge(0, 1);
    g5.add_edge(1, 2);
    g5.add_edge(2, 0);
    g5.add_edge(2, 3);
    g5.add_edge(3, 4);
    g5.add_edge(4, 5);
    g5.add_edge(5, 3);
    g5.add_edge(6, 5);
    g5.add_edge(6, 7);

    auto scc_result = g5.scc();
    int scc_id = 1;
    for (auto& comp : scc_result) {
        cout << "SCC " << scc_id++ << ": ";
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
