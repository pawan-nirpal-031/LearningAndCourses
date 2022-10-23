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


int GetScore(string &s1,string &s2,int i1,int i2){
    if(i1==s1.length() or i2==s2.length()) return 0;
    if(s1[i1]==s2[i2]) return 1 + GetScore(s1,s2,i1+1,i2+1);
    return max(GetScore(s1,s2,i1,i2+1),GetScore(s1,s2,i1+1,i2));
}

int main(){
  FastIO; 
  string s1,s2; 
  cin>>s1>>s2; 
  cout<<GetScore(s1,s2,0,0);
  return 0;
} 
