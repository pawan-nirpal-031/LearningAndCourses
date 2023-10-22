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

bool doesNegetiveCycleExist(vector<edge>&graph,vector<ll> &distance,int nodes){
  distance[1] = 0;
  vector<bool> negetiveCycleNodes(nodes+1,false);
  for(int i = 1;i<=nodes;i++){
    bool relaxed = false;
    for(edge &e : graph){
      if(distance[e.from]+e.w < distance[e.to]){
        distance[e.to] = distance[e.from] + e.w;
        relaxed = true;
      }
    }
    if(i==nodes and relaxed)
      return true;
  }
  return false;
}

int main(){
  FastIO;
  int nodes,edges;
  cin>>nodes>>edges;
  vector<edge>graph;
  vector<ll>distance(nodes+1,Mod);
  for(int ed = 0;ed<edges;ed++){
    int from,to;
    ll weight;
    cin>>from>>to>>weight;
    edge e;
    e.from = from;
    e.to = to;
    e.w = weight;
    graph.push_back(e);
  }
  cout<<(doesNegetiveCycleExist(graph,distance,nodes)?1:0);
  return 0;
}

/*
Principle of Relaxation of Edges for Bellman-Ford:
It states that for the graph having N vertices, all the edges should be relaxed N-1 times to compute the single source shortest path.
In order to detect whether a negative cycle exists or not, relax all the edge one more time and if the shortest distance for any node reduces then we can say that a negative cycle exists. In short if we relax the edges N times, and there is any change in the shortest distance of any node between the N-1th and Nth relaxation than a negative cycle exists, otherwise not exist.
Why Relaxing Edges N-1 times, gives us Single Source Shortest Path?
In the worst-case scenario, a shortest path between two vertices can have at most N-1 edges, where N is the number of vertices. This is because a simple path in a graph with N vertices can have at most N-1 edges, as it’s impossible to form a closed loop without revisiting a vertex.

*/