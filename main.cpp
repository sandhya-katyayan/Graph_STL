#include <iostream>
#include "Graph.hpp"
using namespace std;
int main(){
  Graph g;
  int n, m;
  cout << "Enter the number of vertex and edges in the graph: ";
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
      int u, v, dir;
      cin >> u >> v >> dir;
      g.addEdge(u, v, dir);
  }

  cout << "Printing the adjacency list of the graph:\n";
  g.PrintAdjList();

  cout<<"BFS traversal of the graph is: "<<endl;
  vector<int>bfs=g.BFS(0);
  for(auto i:bfs){
    cout<<i<<"  ";
  }

  cout<<endl;

  cout<<"DFS traversal of the graph is: "<<endl;
  vector<int>dfs=g.DFS(0,n);
  for (auto it:dfs){
    cout<<it<<" ";
    
  }

  cout<<endl<<endl;

  cout<<"Cycle detection in undirected graph using BFS:"<<endl;
  if(g.detectCycleBFS(0,n)){
    cout<<"Cycle is prsent in the graph"<<endl;
  }
  else 
    cout<<"Cycle is not present int the graph"<<endl;

  cout<<endl;

  cout<<"Cycle detection in undirected graph using DFS:"<<endl;
  if(g.detectCycleDfs(0, n)){
    cout<<"Cycle is prsent in the graph"<<endl;
  }
  else{
     cout<<"Cycle is not present int the graph"<<endl;
  }

  cout<<endl;

  cout<<"checking wheather the graph is biparttiate or not using BFS:"<<endl;

  if(g.IsGraphBipartites(n)){
  cout<<"Graph is bipartite "<<endl;
  }

  else{
    cout<<"Graph is not bipartite"<<endl;
  }
  cout<<endl;

  cout<<"Cycle detection in directed graph using DFS:"<<endl;
  if(g.iscycleDirected(n)){
    cout<<"cycle is present in the graph "<<endl;
  }
  else {
    cout<<"cycle is not present in the graph"<<endl;
  }

  cout<<endl;

  cout<<"Topological sort of the graph using DFS:"<<endl;
  vector<int>topo=g.toposort(n);

  for(auto it:topo){
    cout<<it<<" ";
  }
  cout<<endl;


  cout<<"Topological sort of the graph using BFS:"<<endl;
  vector<int>topoBFS=g.toposortBFS(n);


  for(auto it:topoBFS){
    cout<<it<<" ";
  }
  cout<<endl;
  
  

  cout<<"Shortest path in directed acyclic graph using topological sort:"<<endl;

  Graph g1;
  int n1,m1;
  cout<<"Emter the number of vertex and edges in the DAG:"<<endl;
  cin>>n1>>m1;
  int dir=1;
  for(int i=0;i<m1;i++){
    int u,v,weight;
    cin>>u>>v>>weight;
    g1.addEdgewithweight(u, v, weight,dir);
  }

  vector<int>shortestpath=g1.shortestpathdirected(n1, 0);
  for(auto it:shortestpath){
    cout<<it<<" ";
  }
  cout<<endl;

  cout<<"shortest path in weighted graph using dijkstra algorigm : "<<endl;

  vector<int>dijkstra=g1.dijkstra(n1, 0);

  for(auto it:dijkstra){
    cout<<it<<" ";
  }

  cout<<endl;

  cout<<"shortest path in weighted graph using bellman ford algo:"<<endl;

  vector<vector<int> >edges;
  for(int i=0;i<m1;i++){
    int u,v,weight;
    cin>>u>>v>>weight;
    edges.push_back({u,v,weight});
    g1.addEdgewithweight(u, v, weight, dir);
  }


  vector<int>belmanford=g1.bellmanford(n1, 0 ,edges);

  for(auto it:belmanford){
    cout<<it<<" ";
  }

  cout<<endl;


  return 0;
  
}
