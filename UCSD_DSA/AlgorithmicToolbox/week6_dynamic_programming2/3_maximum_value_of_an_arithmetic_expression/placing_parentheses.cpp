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

ll Compute(ll a,ll b,const char &op){
  if(op=='+') return a+b; 
  else if(op=='*') return a*b; 
  else if(op=='-') return a-b; 
  return 0;
}

ll Max(ll a,ll b,ll c,ll d){
  return max(a,max(b,max(c,d)));
}

ll Min(ll a,ll b,ll c,ll d){
  return min(a,min(b,min(c,d)));
}

bool isOpreator(char c){
  return (c=='+' or c=='-' or c=='*');
}

int numcalls = 0;

pair<ll,ll> MaxValueOfExpression(const string &expr,int l,int r,vector<vector<pair<ll,ll>>> &cache,vector<vector<bool>> &vis){
  if(l==r){
    vis[l][r] = 1;
    return cache[l][r] = {expr[l]-'0',expr[l]-'0'};
  }
  numcalls++;  
  if(vis[l][r]) return cache[l][r];
  pair<ll,ll> tuple = {-Mod,Mod};
  for(int i = l;i<=r;i++){
    pair<ll,ll> tuple_2 = {-Mod,Mod};
    if(expr[i]>='0' and expr[i]<='9'){
      for(int j = l;j<=r;j++){
        if(isOpreator(expr[j])){
          auto left = MaxValueOfExpression(expr,l,j-1,cache,vis);
          auto right = MaxValueOfExpression(expr,j+1,r,cache,vis);
          ll lmax = left.first;
          ll lmin = left.second;
          ll rmax = right.first;
          ll rmin = right.second;
          ll a = Compute(lmax,rmax,expr[j]);
          ll b = Compute(lmax,rmin,expr[j]);
          ll c = Compute(lmin,rmax,expr[j]);
          ll d = Compute(lmin,rmin,expr[j]);
          ll maxVal = Max(a,b,c,d);
          ll minVal = Min(a,b,c,d);
          tuple_2.first = max(tuple_2.first,maxVal);
          tuple_2.second = min(tuple_2.second,minVal);
        }
      }
    }
    vis[l][r] = 1; 
    return cache[l][r] = tuple_2;
  }
  return tuple;
}

void solve(){
  string expr;
  cin>>expr;
  int n = expr.length();
  vector<vector<pair<ll,ll>>>cache(n,vector<pair<ll,ll>>(n,{-1,-1}));
  vector<vector<bool>>vis(n,vector<bool>(n,0));
  cout<<MaxValueOfExpression(expr,0,n-1,cache,vis).first<<"\n";
}


int main(){
  FastIO; 
  solve();
  return 0;
} 

