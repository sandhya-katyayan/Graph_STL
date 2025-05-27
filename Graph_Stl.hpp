#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

class Graph{


private:

void dfshelper(int node,unordered_map<int,list<int> >&adj,vector<int>&visited,vector<int>&ans){
  visited[node]=1;
  ans.push_back(node);
  for(auto it:adj[node]){
    if(!visited[it]){
      dfshelper(it,adj,visited,ans);
    }
  }
}





bool detectcycleBFShelper(int src,unordered_map<int,list<int> >&adj,vector<int>&visited){
  visited[src]=1;
  queue<pair<int,int> >q;
  q.push({src,-1});

  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;

    for(auto it:adj[node]){
      if(!visited[it]){
        visited[it]=1;
        q.push({it,node});
        
      }
      else if(parent!=it){
        return true;
      }
    }
  }

  return false;
}





bool detectcycleDfshelper(int node,int parent,unordered_map<int,list<int> >&adj,vector<int>&visited){

  visited[node]=1;
  for(auto adjnode:adj[node]){
    if(!visited[adjnode]){
      if(detectcycleDfshelper(adjnode,node,adj,visited)==true)
        return true;
    }
    else if(adjnode!=parent){
      return true;
    }
  }

  return false;
}


//check for cycle in directed graph helper function 
bool dfscheck(int node,vector<int>&visited,vector<int>&pathvisited){
  visited[node]=1;
  pathvisited[node]=1;

  for(auto it:adj[node]){
    if(!visited[it]){
      if(dfscheck(it,visited,pathvisited)==true)
        return true;
    }

    else if(pathvisited[it]==1){
      return true;
    }
  }


  pathvisited[node]=0;
  return false;
}


void toposortDFS(int node,vector<int>&visited,stack<int>&st){

  visited[node]=1;
  for(auto it:adj[node]){
    if(!visited[it]){
      toposortDFS(it,visited,st);
    }
  }
  st.push(node);
}

public:

unordered_map<int,list<int> >adj;
unordered_map<int,list<pair<int,int> > >adjw;


//Function to add edges int he graph with weight
void addEdgewithweight(int u,int v,int weight,bool dir){
  adjw[u].push_back({v,weight});
  if(dir==0)
    adjw[v].push_back({u,weight});
}


//Function to add Edge in the graph
void addEdge(int u,int v,bool dir){
  adj[u].push_back(v);
  if(dir==0)
    adj[v].push_back(u);
}

//Function to Print the Adjacency List
 void PrintAdjList(){
   for(auto node:adj){
     cout<<node.first<<"->";
     for(auto i:node.second){
       cout<<i<<" ";
     }
     cout << endl; 
   }
 }

//Function to perform Breadth First Search->Time Complexity O(N+2E)

 vector<int> BFS(int source){
   unordered_map<int,bool>Visited;
   queue<int>q;
   q.push(source);
   Visited[source]=true;

   vector<int>bfs;
   while(!q.empty()){
     int frontNode=q.front();
     q.pop();
     bfs.push_back(frontNode);
     for(auto i:adj[frontNode]){
       if(!Visited[i]){
         q.push(i);
         Visited[i]=true;
         
       }
     }
   }

   return bfs;
}

//Function to Perform Depth First search ->Time Complexity O(N+2E)

vector<int>DFS(int source,int n){
  vector<int>visited(n,0);
  vector<int>ans;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfshelper(i,adj,visited,ans);
    }
  }

  return ans;
}

//Function to Detect Cycle in Undirected Graph using BFS->Time Complexity O(N+2E)

bool detectCycleBFS(int source, int n){

   vector<int>visited(n,0);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(detectcycleBFShelper(i,adj,visited)){
        return true;
      }
    }
  }

  return false;
}

//Function to Detect cycle in Undirected Fraph using DFS->Time Complexity O(N+2E)

bool detectCycleDfs(int source,int n){
  vector<int>visited(n,0);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(detectcycleDfshelper(i,-1,adj,visited)==true)
        return true;
    }
  }

  return false;
}


//Function to find whether the graph is bipartite or not using BFS->time complexity O(N+2E)

bool IsGraphBipartites(int vertex){
  vector<int>color(vertex,-1);
  queue<int>q;
  q.push(0);
  color[0]=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      if(color[it]==-1){
        color[it]=!color[it];
        q.push(it);
      }

      else if(color[it]==color[node])
        return false;
    }
  }
  return true;
}

//Function to detect cycle in Directed Graph using DFS ->Time complexity o(N+2E)  on the same path node is visited again then we called there is a cycle

bool iscycleDirected(int vertex){
  vector<int>visited(vertex,0);
  vector<int>Pathvisited(vertex,0);

  for(int i=0;i<vertex;i++){
    if(!visited[i]){
      if(dfscheck(i,visited,Pathvisited)==true)
        return true;
    }
  }

  return false;
}

//function to find the topological sort of the graph using DFS it only exist on DAG.

vector<int>toposort(int vertex){
  vector<int>visited(vertex,0);
  vector<int>ans;
  stack<int>st;

  for(int i=0;i<vertex;i++){
    if(!visited[i]){
      toposortDFS(i,visited,st);
    }
  }

  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }

  return ans;
}

//Function  to perform Kahn's Alfortihm for topological sort  usng BFS

vector<int>toposortBFS(int vertex){
  vector<int>indegree(vertex,0);

  for(int i=0;i<vertex;i++){
    for(auto it:adj[i]){
      indegree[it]++;
    }
  }
  queue<int>q;
  for(int i=0;i<vertex;i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }

  vector<int>topo;

  while(!q.empty()){
    int node=q.front();
    q.pop();

    topo.push_back(node);
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]==0)
        q.push(it);
    }
    
  }

  return topo;
}



//shortest path in directed acyclic graph using toposort on weighted graph

vector<int>shortestpathdirected(int vertex,int source){
  vector<int>topo=toposort(vertex);
  vector<int>Dist(vertex,INT_MAX);
  Dist[source]=0;
  for(auto node:topo){
    for(auto it:adjw[node]){
      int v=it.first;
      int weight=it.second;
      if(Dist[node]!=INT_MAX &&Dist[node]+weight<Dist[v]){
        Dist[v]=Dist[node]+weight;
      }
    }
  }

  return Dist;
}

//function to impliment dijkstra algorithm which is used to find the shortest path in undirected or directed weighted graph  using priority queue data structure

vector<int>dijkstra(int vertex,int source){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  vector<int>dist(vertex,INT_MAX);
  dist[source]=0;
  pq.push({0,source});
  while(!pq.empty()){
    int distance=pq.top().first;
    int prev=pq.top().second;
    pq.pop();
    for(auto it:adjw[prev]){
      int next=it.first;
      int nextdist=it.second;
      if(distance+nextdist<dist[next]){
        dist[next]=distance+nextdist;
        pq.push({dist[next],next});
      }
    
    }
  }
  return dist;
}

//implementing bellman ford algorithm to find the shortest path in weighted graph which can also contain negative weight it helps to detect negative cycle also  and it is only applicable in directed graph

vector<int>bellmanford(int vertex,int source,vector<vector<int> >&edges){
  vector<int>dist(vertex,INT_MAX);
  dist[source]=0;
  for(int i=0;i<vertex-1;i++){
    for(auto it:edges){
      int u=it[0];
      int v=it[1];
      int weight=it[2];
      if(dist[u]!=INT_MAX&& dist[u]+weight<dist[v]){
        dist[v]=dist[u]+weight;
      }
    }
  }

  for(auto it:edges){
    int u=it[0];
    int v=it[1];
    int weight=it[2];
    if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v]){
      cout<<"negative cycle is present";
    }
  }
  return dist;
  
}

//Function to impliment prims algorithm to find the mimumum spanning tree->spanning tree mean n vertices with n-1 edges and all node should be in single comoponent.

/*
int prims(int vertex){
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  vector<int>visited(vertex,0);
  int sum=0;
  pq.push({0,0});
  while(!pq.empty()){
    int weight=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    visited[node]=1;
    sum+=weight;
    for(auto it:adjw[node]){
      int adjnode=it.first;
      int edw=it.second;
      if(!visited[adjnode]){
        pq.push({edw,adjnode});
        visited[adjnode]=1;
        sum+=edw;
      }
      
    }
    
  }
  return sum;
}
*/




};
