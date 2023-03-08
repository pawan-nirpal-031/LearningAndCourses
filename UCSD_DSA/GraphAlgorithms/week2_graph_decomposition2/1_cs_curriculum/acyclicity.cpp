#include <bits/stdc++.h>
using namespace std;
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

vector<pair<int,int>>backEdges;

void RunInSubComponent(int node,vector<int> graph[],vector<int> &visited,bool &hasCycle){
  if(visited[node]==2) return; 
  visited[node] = 1;
  for(int &child : graph[node]){
    if(visited[child]==0){
      RunInSubComponent(child,graph,visited,hasCycle);
    }else if(visited[child]==1){
      hasCycle = 1;
      backEdges.push_back({node,child});
      return;
    }
  }
  visited[node] = 2;
}

int main(){
  FastIO; 
  int nodes,edges;
  cin>>nodes>>edges; 
  vector<int> graph[nodes+1];
  vector<int>visitedStates(nodes+1,0);
  for(int i =0;i<edges;i++){
    int from,to;
    cin>>from>>to; 
    graph[from].push_back(to);
  }
  bool hasCycle = 0;
  for(int i = 1;i<=nodes;i++){
    if(visitedStates[i]==0){
      RunInSubComponent(i,graph,visitedStates,hasCycle);
    }
  }
  cout<<hasCycle;
  return 0;
} 
