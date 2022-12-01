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

int FindRoot(int parent[],int u){
  return parent[u] = (parent[u]==u?u:FindRoot(parent,parent[u]));
}

void Merge(int parent[],int src,int dest){
  parent[src]  = dest;
}

int main(){
  FastIO; 
  int tables, quries; 
  cin>>tables>>quries; 
  int parent[tables]; 
  int rowCount[tables];
  int maxRowCount = -1;
  for(int i =0;i<tables;i++){
    int rows; 
    cin>>rows; 
    parent[i] = i;
    rowCount[i] = rows;
    maxRowCount = max(maxRowCount,rows);
  } 
  /*
    The key insight in keeping a maxRowCount variable and not maxRowCount for each tree is 
    that maxRowCount will always be non-decreasing hence we don't need to iterate over all tree roots to find which is the maximum.  
  */
  for(int q = 0;q<quries;q++){
    int dest,src; 
    cin>>dest>>src; 
    dest--,src--;
    int root1 = FindRoot(parent,src);
    int root2 = FindRoot(parent,dest);  
    if(root1!=root2){ 
      src = root1; 
      dest = root2;
      Merge(parent,src,dest); 
      rowCount[dest]+=rowCount[src]; 
      maxRowCount = max(maxRowCount,rowCount[dest]);
    }
    cout<<maxRowCount<<'\n';
  }
  return 0;
} 
