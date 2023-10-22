#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


struct edge{
  int from,to; 
  int w;
};

void visitUtil(int curr,vector<bool> &hasPathFromSrc,vector<vector<int>> &graph){
  hasPathFromSrc[curr] = true;
  for(int &child : graph[curr]){
    if(not hasPathFromSrc[child]) 
      visitUtil(child,hasPathFromSrc,graph);
  }
}

void visitForPath(int src,vector<bool> &hasPathFromSrc,vector<vector<int>> &graph){
  hasPathFromSrc[src] = true;
  for(int &child : graph[src]){
    visitUtil(child,hasPathFromSrc,graph);
  }
}

void shortestPath(vector<edge>&graph,vector<ll> &distance,int nodes,int src,vector<bool> &hasPathFromSrc){
  distance[src] = 0;
  // a vector to check which nodes are a part of negetive cycle.
  vector<bool> negetiveCycleNodes(nodes+1,false);
  // n-1 relaxations
  for(int i = 1;i<nodes;i++){
    for(edge &e : graph){
      if(distance[e.from]+ e.w < distance[e.to])
        distance[e.to] = distance[e.from] + e.w;
    }
  }
  // the way to check if any node is a part of negetive cyle, the hypothesis is if the edge bearing this node, 
  // relaxes for nth time, than this node must be part of a negetive cycle. 
  for(edge &e : graph){
    if(distance[e.from]+ e.w < distance[e.to]){
      negetiveCycleNodes[e.from] = negetiveCycleNodes[e.to] = true;
      distance[e.to] = distance[e.from] + e.w;
    }
  }
  for(int i = 1;i<=nodes;i++){
    if(not hasPathFromSrc[i]){
      cout<<"*\n";
    }else{
      if(negetiveCycleNodes[i]){
        cout<<"-\n";
      }else{
        if(distance[i]!=Infinity)
          cout<<distance[i]<<"\n";
        else
          assert("should be unreachable");
      }
    }
  }
}


int main(){
  FastIO;
  int nodes,edges;
  cin>>nodes>>edges;
  vector<edge>graph;
  vector<ll>distance(nodes+1,Infinity);
  vector<vector<int>> adjGraph(nodes+1);
  vector<bool>hasPathFromSrc(nodes+1,false);
  for(int ed = 0;ed<edges;ed++){
    int from,to;
    ll weight;
    cin>>from>>to>>weight;
    adjGraph[from].push_back(to);
    edge e;
    e.from = from;
    e.to = to;
    e.w = weight;
    graph.push_back(e);
  }
  int src;
  cin>>src;
  visitForPath(src,hasPathFromSrc,adjGraph);
  shortestPath(graph,distance,nodes,src,hasPathFromSrc);
  return 0;
}
