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


ll ComputeMaximumCost(int i,int wt,vector<pair<ll,ll>>&data,vector<vector<ll>>&cache){
    if(i==-1 or wt==0) return 0; 
    if(cache[i][wt]>-1) return cache[i][wt]; 
    if(data[i].second<=wt){
        return cache[i][wt] = max(
            ComputeMaximumCost(i-1,wt,data,cache),
            data[i].first+ComputeMaximumCost(i-1,wt-data[i].second,data,cache)
        );
    }
    return cache[i][wt] = ComputeMaximumCost(i-1,wt,data,cache);
}

int main(int argc, char **argv){ 
    fstream fin(argv[1]);
    int n,bag_weight; 
    fin>>n>>bag_weight;   
    vector<pair<ll,ll>>data(n,{0,0});
    for(int i =0;i<n;i++) fin>>data[i].first>>data[i].second;
    vector<vector<ll>>cache(n+1,vector<ll>(bag_weight+1,-1));   
    // for(int i =1;i<=n;i++){
    //     for(int j =1;j<=bag_weight;j++){
    //         if(data[i].second<=j){
    //             cache[i][j] = max(cache[i-1][j],data[i].first+cache[i-1][j-data[i].second]);
    //         }else cache[i][j] = cache[i-1][j];
    //     }
    // }
    cout<<ComputeMaximumCost(n-1,bag_weight,data,cache);
}
