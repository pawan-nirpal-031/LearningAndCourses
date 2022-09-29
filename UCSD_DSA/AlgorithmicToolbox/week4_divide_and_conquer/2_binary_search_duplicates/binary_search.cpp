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


int PassOne(int a[],int n,int q){
  int l = 0; 
  int h = n-1; 
  while(l+1<h){
    int m = (l+(h-l)/2);
    if(a[m]==q) return m;
    else if(q>a[m]){
      l = m;
    }else{
      h = m;
    }
  }
  if(a[l]==q) return l;
  if(a[h]==q) return h;
  return -1;
}

int PassTwo(int a[],int n,int x,int upper){
  int h = upper;
  int l =0; 
  while(l+1<h){
    int m = (l+(h-l)/2);
    if(a[m]==x){
      h = m;
    }else l = m;
  }
  if(a[l]==x) return l;
  return h;
}

int SinglePassSolve(int a[],int n,int x){
  int h = n-1; 
  int l = 0; 
  while(l+1<h){
    int m = (l + (h-l)/2);
    if(x<=a[m]){
      h = m;
    }else l = m;
  }
  if(a[l]!=x and a[h]!=x) return -1;
  else if(a[l]==x) return l; 
  return h; 
}

int main(){
  FastIO; 
  int n;
  cin>>n; 
  int a[n];
  for(int &x : a) cin>>x;
  int q;
  cin>>q; 
  while(q--){
    int x;
    cin>>x;  
    cout<<SinglePassSolve(a,n,x)<<' ';
  }
  return 0;
} 
