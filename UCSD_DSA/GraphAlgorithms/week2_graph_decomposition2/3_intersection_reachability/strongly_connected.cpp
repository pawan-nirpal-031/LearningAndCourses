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



void DFSPass1(vector<int> graph[],vector<bool> &visited,stack<int> &processScc,int node){
  if(visited[node]) return;
  visited[node] = 1; 
  for(int &child : graph[node]){
    if(not visited[child]) DFSPass1(graph,visited,processScc,child);
  }
  processScc.push(node);
}


void DFSPass2(vector<int> revGraph[],vector<bool> &visited,stack<int> &processScc,int node){
  visited[node] =1;
  for(int &child : revGraph[node]){
    if(not visited[child]){
      DFSPass2(revGraph,visited,processScc,child);
    }
  }
}

int main(){
  FastIO; 
  int nodes,edges; 
  cin>>nodes>>edges;
  vector<int> graph[nodes+1], revGraph[nodes+1];
  vector<bool>visited(nodes+1,0); 
  for(int e = 0;e<edges;e++){
    int from,to; 
    cin>>from>>to; 
    graph[from].push_back(to);
    revGraph[to].push_back(from);
  }
  stack<int>processScc;
  for(int i =1;i<=nodes;i++){
    if(not visited[i]){ 
      DFSPass1(graph,visited,processScc,i);
    }
  } 
  for(int i = 0;i<=nodes;i++) visited[i] =0;
  int numberComponents = 0;
  while(not processScc.empty()){
    int node = processScc.top();
    processScc.pop();
    if(visited[node]){
      continue;
    }else{
      numberComponents+=1;
      DFSPass2(revGraph,visited,processScc,node);
    }
  } 
  cout<<numberComponents;
  return 0;
}
