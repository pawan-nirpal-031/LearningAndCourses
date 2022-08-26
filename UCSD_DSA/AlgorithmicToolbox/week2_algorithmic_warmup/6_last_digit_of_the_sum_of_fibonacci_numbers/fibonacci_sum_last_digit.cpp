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


void opt(ull n){
    int sum[] = {

      1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 
      2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 
      6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 
      7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 
      6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 
      2, 1, 4, 6, 1, 8, 0, 9, 0, 0

    };

    
    cout<<sum[(n+60-1)%60];
}

int main(){
  FastIO;
  ull n;
  cin>>n;  
  opt(n);
  return 0;
} 
