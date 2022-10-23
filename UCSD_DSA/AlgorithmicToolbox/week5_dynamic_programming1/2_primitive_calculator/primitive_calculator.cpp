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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Debug 0


int nof_calls =0;
int MinOpsToN(int u,int n,vector<int> &cache,vector<int>&path){
    if(cache[u]>-1) return cache[u];
    if(u==n) return cache[u] =  0;
    int min_ops = n-u; 
    int option = 0;
    int ch1,ch2,ch3;
    ch1 = ch2 = ch3 = min_ops;
    if(u*3<=n) ch3 = MinOpsToN(u*3,n,cache,path);
    if(u*2<=n) ch2 = MinOpsToN(u*2,n,cache,path); 
    if(u+1<=n) ch1 = MinOpsToN(u+1,n,cache,path);
    if(min(ch1,min(ch2,ch3))==ch1){
        option = u+1;
    }else if(min(ch1,min(ch2,ch3))==ch2){
        option = u*2;
    }else if(min(ch1,min(ch2,ch3))==ch3){
        option = u*3;
    } 
    min_ops = min(ch1,min(ch2,ch3));
    min_ops+=1;
    path[u] = option;
    nof_calls+=1;
    return cache[u] = min_ops;
}

int main(){
  FastIO; 
  int n;
  cin>>n; 
  vector<int>cache(n+1,-1);
  vector<int>path(n+1,-1);
  cache[n] = 0;
  cache[0] = 1;
  path[0] = 1; 
  cout<<MinOpsToN(1,n,cache,path)<<'\n'; 
  int u = 1;
  for(int i =0;i<=n;i++){
    cout<<u<<' ';
    u = path[u]; 
    if(u==-1) break;
  } 
  return 0;
} 


/*
96234


14
1 2 6 7 21 22 66 198 594 1782 5346 16038 16039 96234 

14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234

*/
