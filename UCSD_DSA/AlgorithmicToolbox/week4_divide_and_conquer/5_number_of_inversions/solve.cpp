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




int main(){
  FastIO; 
  int l = 1;
  int h = 2097151;
  while(l+1<h){
    int m =((l+h)>>1);
    cout<<m<<endl;
    char c;
    cin>>c; 
    if(c=='h'){
        l = m;
    }else if(c=='e'){
        break;
    }else{
        h = m;
    }
  }
  return 0;
} 
