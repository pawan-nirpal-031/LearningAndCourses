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



void InOrder(const vector<pair<int,int>> &graph,const vector<int> &values,int node){
  assert(node!=-1 && "invalid node");
  if(graph[node].first!=-1) InOrder(graph,values,graph[node].first);
  cout<<values[node]<<' ';
  if(graph[node].second!=-1) InOrder(graph,values,graph[node].second);
} 

void PreOrder(const vector<pair<int,int>> &graph,const vector<int> &values,int node){
  assert(node!=-1 && "invalid node");
  cout<<values[node]<<' ';
  if(graph[node].first!=-1) PreOrder(graph,values,graph[node].first);
  if(graph[node].second!=-1) PreOrder(graph,values,graph[node].second);
}

void PostOrder(const vector<pair<int,int>> &graph,const vector<int> &values,int node){
  assert(node!=-1 && "invalid node");
  if(graph[node].first!=-1) PostOrder(graph,values,graph[node].first);
  if(graph[node].second!=-1) PostOrder(graph,values,graph[node].second);
  cout<<values[node]<<' ';
}

int main(){
  FastIO; 
  int nodes; 
  cin>>nodes;
  vector<pair<int,int>>graph(nodes,{-1,-1}); 
  vector<int>values(nodes,0);
  for(int i =0;i<nodes;i++){
    int val,left,right; 
    cin>>val>>left>>right; 
    values[i] = val; 
    graph[i].first = left; 
    graph[i].second = right;
  }
  InOrder(graph,values,0);
  cout<<'\n';
  PreOrder(graph,values,0);  
  cout<<'\n';
  PostOrder(graph,values,0);
  return 0;
} 
