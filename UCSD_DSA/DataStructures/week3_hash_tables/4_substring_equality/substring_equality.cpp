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




ll prime1 = Mod; 
ll prime2 = Mod+2;
ll x = 1+rand()%1000000000;

ll GetInt(const char &x){
  return x;
}

ll ModuloProductP1(ll a,ll b){
  ll res = (a%prime1 * b%prime1)%prime1;
  return res;
}

ll ModuloProductP2(ll a,ll b){
  ll res = (a%prime2 * b%prime2)%prime2;
  return res;
}

ll GetExpoP1(int l){
  if(l==0) return 1; 
  if(l==1) return x; 
  ll half = GetExpoP1(l>>1);
  ll mod_prod_half = ModuloProductP1(half,half);
  if(l&1) return ModuloProductP1(x,mod_prod_half)%prime1;
  return mod_prod_half;
}


ll GetExpoP2(int l){
  if(l==0) return 1; 
  if(l==1) return x; 
  ll half = GetExpoP2(l>>1);
  ll mod_prod_half = ModuloProductP2(half,half);
  if(l&1) return ModuloProductP2(x,mod_prod_half)%prime2;
  return mod_prod_half;
}

int main(){
  FastIO;
  string text; 
  cin>>text; 
  int quries; 
  cin>>quries; 
  int len = text.length(); 
  vector<ull>firstLvlHash(len+1,0),secondLvlHash(len+1,0);  
  vector<ull>levelOnePow(len+1,0),levelTwoPow(len+1,0);
  levelOnePow[0] = levelTwoPow[0] = 1;
  for(int i =1;i<=len;i++){
    firstLvlHash[i] = (x*firstLvlHash[i-1] + GetInt(text[i-1]))%prime1; 
    secondLvlHash[i] = (x*secondLvlHash[i-1] + GetInt(text[i-1]))%prime2;
    levelOnePow[i] = (x%prime1 * levelOnePow[i-1]%prime1)%prime1; 
    levelTwoPow[i] = (x%prime2 * levelTwoPow[i-1]%prime2)%prime2;
  } // H(a,l) = h[a+l] - h[a]*x^l
  while(quries--){
    int a,b,l; 
    cin>>a>>b>>l; 
    ll prim_hash_a,prim_hash_b,sec_hash_a,sec_hash_b; 
    ll y1 = levelOnePow[l];
    ll y2 = levelTwoPow[l];
    prim_hash_a = (prime1 +  firstLvlHash[a+l] - (y1%prime1*firstLvlHash[a]%prime1))%prime1;
    sec_hash_a = (prime2 + secondLvlHash[a+l] - (y2%prime2*secondLvlHash[a]%prime2))%prime2;
    prim_hash_b = (prime1 + firstLvlHash[b+l] - (y1%prime1*firstLvlHash[b]%prime1))%prime1;
    sec_hash_b = (prime2 + secondLvlHash[b+l] - (y2%prime2*secondLvlHash[b]%prime2))%prime2;
    if((prim_hash_a==prim_hash_b) and (sec_hash_a==sec_hash_b)) cout<<"Yes\n";
    else cout<<"No\n";
  }     
  return 0;
} 

