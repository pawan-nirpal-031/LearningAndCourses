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
#define Debug 0

ll levl1 = Mod; 
ll levl2 = Mod+2;
ll x = 1+rand()%1000000000;


ll GetInt(const char &x){ 
    return x;
}

struct Query{
  bool state;
  int str1st_indx; 
  int str2st_indx; 
  Query(){
    state =0; 
    str1st_indx = str2st_indx = -1;
  }
};

void PrecomputePrefixHashes(const string &text,vector<ull>&firstLvlHash,vector<ull> &secondLvlHash,vector<ull> &levelOnePow,vector<ull> &levelTwoPow){
    int len = text.length();
    levelOnePow[0] = levelTwoPow[0] = 1;
    for(int i =1;i<=len;i++){
      firstLvlHash[i] = (x*firstLvlHash[i-1] + GetInt(text[i-1]))%levl1; 
      secondLvlHash[i] = (x*secondLvlHash[i-1] + GetInt(text[i-1]))%levl2;
      levelOnePow[i] = (x%levl1 * levelOnePow[i-1]%levl1)%levl1; 
      levelTwoPow[i] = (x%levl2 * levelTwoPow[i-1]%levl2)%levl2;
    }
} 

void DebugHashsesAndPowers(int len, vector<ull>&firstLvlHash,vector<ull> &secondLvlHash,vector<ull> &levelOnePow,vector<ull> &levelTwoPow){
  for(int i =0;i<=len;i++){
      cout<<"L1 Hash : "<<firstLvlHash[i]<<" L2 Hash : "<<secondLvlHash[i]<<" L1 Pow : "<<" L2 Pow : "<<levelTwoPow[i]<<"\n";
  }
}

Query CommonSubstring(int k,const string &s1,const string &s2){
  int len1 = s1.length();
  int len2 = s2.length();
  vector<ull>S1firstLvlHash(len1+1,0),S1secondLvlHash(len1+1,0);
  vector<ull>S1levelOnePow(len1+1,1),S1levelTwoPow(len1+1,1);
  PrecomputePrefixHashes(s1,S1firstLvlHash,S1secondLvlHash,S1levelOnePow,S1levelTwoPow);
  vector<ull>S2firstLvlHash(len2+1,0),S2secondLvlHash(len2+1,0);
  vector<ull>S2levelOnePow(len2,1),S2levelTwoPow(len2+1,1);
  PrecomputePrefixHashes(s2,S2firstLvlHash,S2secondLvlHash,S2levelOnePow,S2levelTwoPow);
  unordered_map<ull,int>Lvl1S1CacheBuild,Lvl2S1CacheBuild;
  for(int i =k-1;i<len1;i++){
    ull l1Hash = S1firstLvlHash[i];
    ull l2Hash = S1secondLvlHash[i];
    ull pow1 = S1levelOnePow[i];
    ull pow2 = S1levelTwoPow[i];
    ull Substrl1Hash = (levl1 + S1firstLvlHash[i] - (pow1%levl1 * S1firstLvlHash[i-(k-1)]%levl1)%levl1)%levl1;
    ull Substrl2Hash = (levl2 + S1secondLvlHash[i] - (pow2%levl2 * S1secondLvlHash[i-(k-1)]%levl2)%levl2)%levl2;
    Lvl1S1CacheBuild.insert({Substrl1Hash,i-k-1});
    Lvl2S1CacheBuild.insert({Substrl2Hash,i-k-1});
  }
  Query result;
  for(int i = k-1;i<len2;i++){
    ull pow1 = S2levelOnePow[i];
    ull pow2 = S2levelTwoPow[i];
    ull l1Hash = (levl1 + S2firstLvlHash[i] - (pow1%levl1 * S2firstLvlHash[i-(k-1)]%levl1)%levl1)%levl1;
    ull l2Hash = (levl2 + S2secondLvlHash[i] - (pow2%levl2 * S2secondLvlHash[i-(k-1)]%levl2)%levl2)%levl2;
    auto L1it = Lvl1S1CacheBuild.find(l1Hash);
    auto L2it = Lvl2S1CacheBuild.find(l2Hash);
    if(L1it!=Lvl1S1CacheBuild.end() and L2it!=Lvl2S1CacheBuild.end()){
      if(L1it->first==l1Hash and L2it->first==l2Hash){
        result.state = 1; 
        result.str1st_indx = L1it->first;
        result.str2st_indx = i-k-1;
      }
    }
  }
  return result;
  
}

void Solve(const string &s1,const string &s2){
  int len1 = s1.length(); 
  int len2 = s2.length(); 
  int low = 0; 
  int high = min(len1,len2); 
  int stindx1 = -1;
  int stindx2 = -1;
  for(int x = 0;x<=high;x++){
    int mid = (low + (high-low)>>1);
    Query q = CommonSubstring(x,s1,s2);
    if(q.state){
      low = x;
      stindx1 = q.str1st_indx;
      stindx2 = q.str2st_indx;
    }else break;
  }
  cout<<stindx1<<' '<<stindx2<<' '<<low<<'\n';
}

int main(){
  ifstream fin("input.txt");
  vector<string>data; 
  string tmp;
  while(fin>>tmp){
    data.push_back(tmp);
  }
  for(int i =0;i<data.size();i+=2){
    string &s1 = data[i];
    string &s2 = data[i+1];
    Solve(s1,s2);
  }
  return 0;
}