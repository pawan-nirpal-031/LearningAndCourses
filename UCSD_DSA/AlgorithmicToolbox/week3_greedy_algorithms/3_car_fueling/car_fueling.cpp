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

/*
  Greedy hypothesis : Do not refuel at the current station if the next station can be reached. 
  If the next station is not reachable, then check if a refuel can make it reachable 
  if still the next station is not reachable with a refuel then it is not possible. But if yes 
  then refuel and move to the next staion. Basically Refuel at the furtest reachable station from current station.


  10 6 
  2 
  3 7
   
  2 

*/

int main(){ 
  FastIO; 
  int tot_dist,max_dist_on_refuel; 
  int n; 
  cin>>tot_dist>>max_dist_on_refuel>>n; 
  int stations[n+2]; 
  stations[0] = 0;
  stations[n+1] = tot_dist;
  for(int i = 1;i<=n;i++) cin>>stations[i];
  int refuls =0; 
  int curr_fuel = max_dist_on_refuel;  
  for(int i =0;i<n+1;i++){
    int dist_to_cover = stations[i+1] - stations[i]; 
    if(curr_fuel>=dist_to_cover){
      curr_fuel-=dist_to_cover; 
    }else{ 
      if(max_dist_on_refuel<dist_to_cover){ 
        refuls = -1; 
        break;
      }
      curr_fuel = max_dist_on_refuel;  
      refuls+=1;
      curr_fuel-=dist_to_cover;
    }
  }
  cout<<refuls<<'\n';
  return 0;
} 
 