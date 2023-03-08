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


void TopologicalOrder(vector<int> graph[],vector<int> &inDegree){
  queue<int>ProcessingNodes; 
  int nodes = inDegree.size() - 1; 
  for(int i = 1;i<=nodes;i++){
    if(inDegree[i]==0) ProcessingNodes.push(i);
  }
  while(ProcessingNodes.size()!=0){
    int currNode = ProcessingNodes.front(); 
    ProcessingNodes.pop(); 
    cout<<currNode<<" "; 
    for(int &child : graph[currNode]){
      inDegree[child]--; 
      if(inDegree[child]==0) ProcessingNodes.push(child);
    }
  }
}

int main(){
  FastIO; 
  int nodes,edges; 
  cin>>nodes>>edges; 
  vector<int> graph[nodes+1];
  vector<int>inDegree(nodes+1,0); 
  for(int i =0;i<edges;i++){
    int from,to; 
    cin>>from>>to; 
    inDegree[to]++; 
    graph[from].push_back(to);
  }
  TopologicalOrder(graph,inDegree);
  return 0;
} 
