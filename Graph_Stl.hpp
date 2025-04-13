#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

namespace graphstl {

    template<typename T>
    class Graph {
    private:
        unordered_map<T, list<pair<T, int>>> adj;
        bool isDirected;
        vector<vector<int>> adjacency_list;
        int vertices;

    public:
        Graph(bool isDir = false) : isDirected(isDir) {}

        Graph(int n) : vertices(n) {
            adjacency_list.resize(n);
        }

        void add_vertex(T u) {
            if (adj.find(u) == adj.end())
                adj[u] = {};
        }

        void add_edge(T u, T v, int weight = 1) {
            add_vertex(u);
            add_vertex(v);
            adj[u].push_back({v, weight});
            if (!isDirected) {
                adj[v].push_back({u, weight});
            }

            // Also update adjacency list for graph algorithms
            if (u < adjacency_list.size() && v < adjacency_list.size()) {
                adjacency_list[u].push_back(v);
                if (!isDirected) {
                    adjacency_list[v].push_back(u);
                }
            }
        }

        list<pair<T, int>>& getAdjList(T node) {
            return adj[node];
        }

        vector<T> dfs(T start) const {
            unordered_map<T, bool> visited;
            vector<T> result;
            dfsHelper(start, visited, result);
            return result;
        }

        vector<T> bfs(T start) const {
            unordered_map<T, bool> visited;
            queue<T> q;
            vector<T> result;

            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                T node = q.front(); q.pop();
                result.push_back(node);
                for (auto [neighbor, _] : adj.at(node)) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            return result;
        }

        vector<T> topological_sort() const {
            map<T, int> in_degree;
            for (const auto& entry : adj) {
                if (in_degree.find(entry.first) == in_degree.end())
                    in_degree[entry.first] = 0;
                for (const auto& neighbor : entry.second) {
                    in_degree[neighbor.first]++;
                }
            }

            queue<T> q;
            for (const auto& item : in_degree) {
                if (item.second == 0) q.push(item.first);
            }

            vector<T> topo;
            while (!q.empty()) {
                T node = q.front(); q.pop();
                topo.push_back(node);
                for (const auto& neighbor : adj.at(node)) {
                    in_degree[neighbor.first]--;
                    if (in_degree[neighbor.first] == 0)
                        q.push(neighbor.first);
                }
            }

            return topo;
        }

        map<T, int> dijkstra(T src) const {
            map<T, int> dist;
            for (auto& entry : adj) dist[entry.first] = INT_MAX;
            dist[src] = 0;
            set<pair<int, T>> s;
            s.insert({0, src});

            while (!s.empty()) {
                auto [d, node] = *s.begin();
                s.erase(s.begin());

                for (auto [neighbor, weight] : adj.at(node)) {
                    if (d + weight < dist[neighbor]) {
                        s.erase({dist[neighbor], neighbor});
                        dist[neighbor] = d + weight;
                        s.insert({dist[neighbor], neighbor});
                    }
                }
            }
            return dist;
        }

        vector<tuple<int, T, T>> kruskal_mst() const {
            vector<tuple<int, T, T>> edges;
            for (auto& [u, neighbors] : adj) {
                for (auto& [v, w] : neighbors) {
                    if (u < v) edges.push_back({w, u, v});
                }
            }
            sort(edges.begin(), edges.end());

            unordered_map<T, T> parent;
            for (auto& entry : adj) parent[entry.first] = entry.first;

            function<T(T)> find = [&](T node) {
                if (parent[node] != node)
                    parent[node] = find(parent[node]);
                return parent[node];
            };

            vector<tuple<int, T, T>> result;
            for (auto& [w, u, v] : edges) {
                T pu = find(u), pv = find(v);
                if (pu != pv) {
                    parent[pu] = pv;
                    result.push_back({w, u, v});
                }
            }
            return result;
        }

        bool has_cycle() {
            vector<bool> visited(vertices, false);
            for (int i = 0; i < vertices; i++) {
                if (!visited[i] && has_cycle_util(i, visited, -1)) {
                    return true;
                }
            }
            return false;
        }

        vector<vector<int>> scc() {
            stack<int> stack;
            vector<bool> visited(vertices, false);

            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    dfs1(i, visited, stack);
                }
            }

            reverse_graph();

            fill(visited.begin(), visited.end(), false);
            vector<vector<int>> components;

            while (!stack.empty()) {
                int v = stack.top();
                stack.pop();

                if (!visited[v]) {
                    vector<int> component;
                    dfs2(v, visited, component);
                    components.push_back(component);
                }
            }

            return components;
        }

    private:
        void dfsHelper(T node, unordered_map<T, bool>& visited, vector<T>& result) const {
            visited[node] = true;
            result.push_back(node);
            for (auto [neighbor, _] : adj.at(node)) {
                if (!visited[neighbor])
                    dfsHelper(neighbor, visited, result);
            }
        }

        bool has_cycle_util(int v, vector<bool>& visited, int parent) {
            visited[v] = true;
            for (int neighbor : adjacency_list[v]) {
                if (!visited[neighbor]) {
                    if (has_cycle_util(neighbor, visited, v)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    return true;
                }
            }
            return false;
        }

        void dfs1(int v, vector<bool>& visited, stack<int>& stack) {
            visited[v] = true;
            for (int neighbor : adjacency_list[v]) {
                if (!visited[neighbor]) {
                    dfs1(neighbor, visited, stack);
                }
            }
            stack.push(v);
        }

        void dfs2(int v, vector<bool>& visited, vector<int>& component) {
            visited[v] = true;
            component.push_back(v);
            for (int neighbor : adjacency_list[v]) {
                if (!visited[neighbor]) {
                    dfs2(neighbor, visited, component);
                }
            }
        }

        void reverse_graph() {
            vector<vector<int>> reversed(vertices);
            for (int i = 0; i < vertices; i++) {
                for (int neighbor : adjacency_list[i]) {
                    reversed[neighbor].push_back(i);
                }
            }
            adjacency_list = reversed;
        }
    };
}

#endif // GRAPH_HPP