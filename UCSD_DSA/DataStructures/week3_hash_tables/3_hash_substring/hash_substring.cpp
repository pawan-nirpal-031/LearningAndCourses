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


bool AreEqual(const string &text,const string &pattern,int si,int ei){
    for(int i =0;i<pattern.size();i++){
        if(pattern[i]!=text[si+i]) return false; 
    }
    return true;
}

ll PolynomialHash(const string &str,ll prime,ll x,int si,int ei){
    ll hash_val = 0; 
    for(int i = ei;i>=si;i--) hash_val = (hash_val*x+str[i])%prime;
    return hash_val;
} 


ll GetInt(const char &x){ 
    return x;
}


void PrecomputeSubstringHashes(vector<ll> &substring_hashes,const string &text,const string &pattern,ll prime,ll x){
    int text_len = text.length(); 
    int pattern_len = pattern.length(); 
    substring_hashes[text_len-pattern_len] = PolynomialHash(text,prime,x,text_len-pattern_len,text_len-1); 
    ll y = 1;
    for(int i =0;i<pattern_len;i++) y = (x*y)%prime; // can still be optimized to O(log(|P|)) 
    for(int i = text_len-pattern_len-1;i>=0;i--){
        substring_hashes[i] = (x*substring_hashes[i+1] + GetInt(text[i]) - y*GetInt(text[i+pattern_len]))%prime;
    }
}

void RabinKarpSubstringSearch(const string &text,const string &pattern){
    vector<int>positions; 
    ll prime = Mod; 
    ll x = 1 + rand()%prime; 
    ll pattern_hash = PolynomialHash(pattern,prime,x,0,pattern.length()-1);  
    assert(text.length()>=pattern.length());
    vector<ll>substring_hashes(text.length()-pattern.length()+1,0);  
    PrecomputeSubstringHashes(substring_hashes,text,pattern,prime,x);
    for(int i =0;i<=text.length()-pattern.length();i++){
        ll substr_hash = substring_hashes[i]; 
        if(substr_hash!=pattern_hash) continue;  
        if(AreEqual(text,pattern,i,i+pattern.length()-1)) positions.push_back(i); /// The probablity of this condition being hit is too less thanks to a large prime number.
    }   
    for(int &x : positions) cout<<x<<' ';
}

int main(){
  FastIO; 
  string pattern,text;
  cin>>pattern>>text;
  RabinKarpSubstringSearch(text,pattern);
  return 0;
} 
