#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

bool bipartite_util(vector<int>g[], vector<bool>&vis,vector<bool>& col,int c,int u){
  vis[u] = 1; 
  col[u] = c; 
  for(int &v : g[u]){
    if(not vis[v]) return bipartite_util(g,vis,col,(c^1),v);
    else{
      if(col[u]==col[v]) return 0;
    }
  }
  return 1;
}

int bipartite(vector<int> g[],int n,int m) {
  vector<bool>vis(n+1,0); 
  vector<bool>color(n+1,0); 
  bool isBip = 1; 
  for(int i =1;i<=n;i++){
    if(not vis[i]) isBip = isBip and bipartite_util(g,vis,color,1,i);
  } 
  return isBip;
}

// /home/pnirpal/Workspace/Learning/Courses/UCSD_DSA/GraphAlgorithms/week3_paths_in_graphs1/2_bipartite/a.out

/*

7 6 
1 2 
1 3 
4 5 
4 6
5 7 
6 7 

*/

int main() {
  int n,m; 
 // cin>>n>>m;  
  n = 7; 
  m = 6; 
  vector<int> g[n+1];  
  vector<pair<int,int>>inp = {
    {1, 2 },
    {1 ,3 },
   { 4 ,5 },
   { 4, 6},
    {5, 7 },
   { 6, 7 }
  }; 
  for(int i =0;i<m;i++){
    int x,y; 
   // cin>>x>>y; 
    x = inp[i].first; 
    y = inp[i].second;
    g[x].push_back(y); 
    g[y].push_back(x);
  }
  cout<<(bipartite(g,n,m)?1:0);
}
