#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity 18446744073709551615
#define Pair(a,b) make_pair(a,b)
#define IncresePrecision(x) std::fixed<<setprecision(8)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"1\n":"0\n"));
#define Debug 0



int GetFurthest(vector<int> tree[],int root,int n){
  vector<int>dist(n,0);
  vector<bool>vis(n,0);
  queue<int> process; 
  process.push(root);
  while(not process.empty()){
    int next = process.front();
    process.pop(); 
    vis[next] = 1; 
    if(next==root) dist[next] = 0; 
    for(const int &subs : tree[next]){
      if(vis[subs]) continue;
      process.push(subs);
      dist[subs] = 1+dist[next];
    }
  }  
  int max_in_row = 0;
  for(const int &x : dist) max_in_row = max(max_in_row,x);
  return max_in_row+1;
}


void solve(){
  int n;
  cin>>n;
  int root = -1;
  vector<int> tree[n];
  for(int i =0;i<n;i++){
    int par; 
    cin>>par; 
    if(par==-1){
      root = i;
    }else{
      tree[par].push_back(i);
    }
  }
  cout<<GetFurthest(tree,root,n); 
}



int main(){
  FastIO; 
  solve();
  return 0;
} 

