#include <iostream>
#include <vector>
#include <queue>
using namespace std; 


void InspectComponent( vector<vector<int>> &graph,int node,vector<bool> &visited,vector<bool> &colour, bool nodeCol,bool  &isBipartite){
  visited[node] = 1;
  colour[node] = nodeCol;
  for(int &child : graph[node]){
    if(not visited[child]){
      InspectComponent(graph,child,visited,colour,nodeCol^1,isBipartite);
    }else{
      isBipartite = isBipartite and colour[node]!=colour[child]; 
      if(isBipartite==0) return;
    }
  }
}

int main() {
  int nodes,edges;
  cin>>nodes>>edges; 
  vector<vector<int>>graph(nodes+1);
  vector<bool>visited(nodes+1,0);
  vector<bool>colour(nodes+1,0);
  for(int i =0;i<edges;i++){
    int x,y; 
    cin>>x>>y; 
    graph[x].push_back(y); 
    graph[y].push_back(x);
  }
  bool isBipartite = 1;
  for(int i = 1;i<=nodes;i++){
    if(not visited[i]){
      InspectComponent(graph,i,visited,colour,0,isBipartite); 
      if(isBipartite==0) break;
    }
  }
  cout<<isBipartite;
}
