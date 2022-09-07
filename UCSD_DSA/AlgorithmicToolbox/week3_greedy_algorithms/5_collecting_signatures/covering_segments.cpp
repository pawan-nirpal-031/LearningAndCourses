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

bool compare(const pair<int,int> &a,const pair<int,int> &b){
  return b.second>a.second;
}


/* 
  The furthest line starting or ending from current point that is not 
  enclosed in it's range will be included. 
*/


int main(){
  FastIO; 
  int n; 
  cin>>n; 
  vector<pair<int,int>>lines(n,{0,0}); 
  for(int i =0;i<n;i++) cin>>lines[i].first>>lines[i].second; 
  sort(lines.begin(),lines.end(),compare);
  vector<int>vertical; 
  int point = lines[0].second; 
  vertical.push_back(point);
  for(int i =1;i<n;i++){
    if(point<lines[i].first or point>lines[i].second){ 
      point = lines[i].second; 
      vertical.push_back(point);
    }
  }
  cout<<vertical.size()<<'\n';
  for(int &x : vertical) cout<<x<<' ';  
  return 0;
} 
