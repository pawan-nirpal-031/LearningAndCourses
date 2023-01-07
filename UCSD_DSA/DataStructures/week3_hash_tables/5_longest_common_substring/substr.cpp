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

ull levl1 = Mod;
ull levl2 = Mod+2;
ll x = 35;


ll GetInt(const char &x){ 
    return x;
}

struct Query{
    bool state; 
    int indx1,indx2; 
    Query(){
        state = 0; 
        indx1 = indx1 = -1;
    }
};
 
Query DoesCommonSubstrExist(string &s1,string &s2,int k){
    int l1 = s1.length();
    int l2 = s2.length();
    vector<ll>S1PHash(l1+1,0),S1SHash(l1+1,0),S2PHash(l2+1,0),S2SHash(l2+1,0);
    ll powlvl1 = 1; 
    ll powlvl2 = 1;
    for(int i =0;i<k;i++){
        powlvl1 = (powlvl1*x)%levl1; 
        powlvl2 = (powlvl2*x)%levl2;
    }
    for(int i = 1;i<=l1;i++){
        S1PHash[i] = (x*S1PHash[i-1] + GetInt(s1[i-1]))%levl1;
        S1SHash[i] = (x*S1SHash[i-1] + GetInt(s1[i-1]))%levl2;
    }
    for(int i = 1;i<=l2;i++){   
        S2PHash[i] = (x*S2PHash[i-1] + GetInt(s2[i-1]))%levl1; 
        S2SHash[i] = (x*S2SHash[i-1] + GetInt(s2[i-1]))%levl2;
    }
    unordered_multimap<ll,int>S1CacheL1,S1CacheL2; 
    for(int i =0;i<=l1-k;i++){
        ll primary_hash = (levl1 + S1PHash[i+k] - (S1PHash[i]*powlvl1)%levl1)%levl1;
        ll secondary_hash = (levl2 + S1SHash[i+k] - (S1SHash[i]*powlvl2)%levl2)%levl2;
        S1CacheL1.insert({primary_hash,i}); 
        S1CacheL2.insert({secondary_hash,i});
    }
    Query query; 
    for(int i = 0;i<=l2-k;i++){
        ll primary_hash = (levl1 + S2PHash[i+k] - (S2PHash[i]*powlvl1)%levl1)%levl1;
        ll secondary_hash = (levl2 + S2SHash[i+k] - (S2SHash[i]*powlvl2)%levl2)%levl2;
        auto it1 = S1CacheL1.find(primary_hash);
        auto it2 = S1CacheL2.find(secondary_hash); 
        if(it1!=S1CacheL1.end() and it2!=S1CacheL2.end()){
            if(it1->first==primary_hash and it2->first==secondary_hash){
                query.state = 1; 
                query.indx1 = it1->second; 
                query.indx2 = i;
            }
        }
    }   
    return query;
}


void Solve(string &s1,string &s2){
    int l1 = s1.length(); 
    int l2 = s2.length();
    if(DoesCommonSubstrExist(s1,s2,1).state==false){
        cout<<0<<' '<<0<<' '<<0<<'\n'; 
        return;
    }
    int low = 1; 
    int high = min(l1,l2);  
    Query answer;
    while(low<=high){
        int m = (low+high)/2; 
        Query local = DoesCommonSubstrExist(s1,s2,m); 
        if(local.state){
            answer.indx1 = local.indx1; 
            answer.indx2 = local.indx2;
            low = m+1;
        }else{  
            high = m-1;
        }
    }
    cout<<answer.indx1<<" "<<answer.indx2<<' '<<low-1<<'\n';
}


int main(){
    vector<string>data; 
    string s1,s2; 
    while(cin>>s1>>s2){
        Solve(s1,s2);
    }
    return 0;
}

/*

cool toolbox
aaa bb
aabaa babbaab


*/