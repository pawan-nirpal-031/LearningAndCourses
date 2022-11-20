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


void Solve(){
    int n; 
    cin>>n;
    int a[n];
    for(int &x : a) cin>>x;
    int win; 
    cin>>win;
    deque<int>process; 
    for(int i =0;i<win;i++){
        if(process.empty()){
            process.push_front(a[i]);
            continue;
        }
        while(process.size() and process.back()<a[i]) process.pop_back(); 
        process.push_back(a[i]);
    }
    for(int i = win;i<n;i++){
        cout<<process.front()<<' ';
        if(process.empty()){    
            process.push_front(a[i]);
            continue;
        }
        if(process.front()==a[i-win]) process.pop_front(); 
        while(process.size() and process.back()<a[i]) process.pop_back(); 
        process.push_back(a[i]);
    } 
    cout<<process.front();
    process.clear();
}

/*

8
2 7 3 1 5 2 6 2
4

7 7 5 6 6 
*/

int main(){
  FastIO; 
  Solve();
  return 0;
} 

