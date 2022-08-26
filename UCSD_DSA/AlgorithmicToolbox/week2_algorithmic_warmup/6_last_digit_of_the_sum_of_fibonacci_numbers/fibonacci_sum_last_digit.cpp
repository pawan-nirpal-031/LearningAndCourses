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


void naive(int n){
    vector<ll>fib(n+1,0); 
    fib[0] = fib[1] = 1; 
    for(int i = 2;i<=n;i++) fib[i] = fib[i-1]+fib[i-2]; 
    vector<ll>smod(n+1,0); 
    smod[0] = 1; 
    for(int i =1;i<=n;i++){
        smod[i] = (smod[i-1]+fib[i])%10;
    }
    for(int i =0;i<=n;i++) cout<<smod[i]<<' ';
}

int main(){
  FastIO;
  int n;
  cin>>n; 
  naive(n);
  return 0;
} 
