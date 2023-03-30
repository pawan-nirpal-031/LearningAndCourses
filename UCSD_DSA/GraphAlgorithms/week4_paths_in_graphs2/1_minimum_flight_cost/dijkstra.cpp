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

void NaiveAlgorithm(int source,int dest,vector<bool> &visited,vector<ll> &distance,vector<vector<pair<int,ll>>> &graph,int nodes){
  int currNode = source; 
  distance[currNode] = 0;
  while(currNode!=dest){
    for(auto &tuple : graph[currNode]){ // relax each of the edges from current node 
      int child = tuple.first;
      ll edgeWeight = tuple.second;
      if(visited[child]) continue; 
      if(distance[currNode]+edgeWeight<distance[child]){
        distance[child] = distance[currNode]+edgeWeight;
      }
    }
    visited[currNode] = 1;
    int NextCand = -1;
    ll NextDist = Mod;
    for(auto &tuple : graph[currNode]){
      if(visited[tuple.first]) continue;
      if(distance[tuple.first]<NextDist){
        NextCand = tuple.first;
        NextDist = distance[tuple.first];
      }
    }
    if(NextCand==-1) break;
    currNode = NextCand;
  }
  for(int i =1;i<=nodes;i++){
    cout<<i<<" "<<distance[i]<<'\n';
  }
}

void OptimizedAlgorithm(int source,int dest,vector<bool> &visited,vector<ll> &distance,vector<vector<pair<int,ll>>> &graph){
  int nodes = graph.size()-1; 
  distance[source] = 0;
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>processing; 
  processing.push({distance[source],source});
  while(processing.size()){
    auto tuple = processing.top(); 
    processing.pop();
    int currNode = tuple.second;
    if(visited[currNode]) continue;
    ll srcToCurrNodeDist = tuple.first;
    for(auto &neighbours : graph[currNode]){
      int child = neighbours.first;
      if(visited[child]) continue;
      int edgeWeight = neighbours.second;
      if(srcToCurrNodeDist+edgeWeight<distance[child]){
        distance[child] = srcToCurrNodeDist+edgeWeight;
        processing.push({distance[child],child});
      }
    }
    visited[currNode] = true;
  }
  for(int i = 1;i<=nodes;i--){
    cout<<distance[i]<<" ";
  }
}


int main(){
  FastIO; 
  int nodes,edges; 
  cin>>nodes>>edges; 
  vector<vector<pair<int,ll>>>graph(nodes+1); // src -> {(dest,weight)..} 
  vector<bool>visited(nodes+1,0);
  vector<ll>distance(nodes+1,Mod); 
  for(int ed = 0;ed<edges;ed++){
    int from,to;
    ll weight; 
    cin>>from>>to>>weight; 
    graph[from].push_back({to,weight});
  }
  int source,dest;
  cin>>source>>dest;
  //OptimizedAlgorithm(source,dest,visited,distance,graph);
  OptimizedAlgorithm(source,dest,visited,distance,graph);
  return 0;
} 
