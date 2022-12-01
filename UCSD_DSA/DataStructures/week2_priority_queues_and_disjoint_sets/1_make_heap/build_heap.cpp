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

void ShiftDown(int a[],int i,int n,vector<pair<int,int>> &swaps){
  int min_indx = i; 
  int left = 2*i+1; 
  int right = 2*i+2; 
  if(left<n and a[left]<a[min_indx]) min_indx = left; 
  if(right<n and a[right]<a[min_indx]) min_indx = right; 
  if(i!=min_indx){
    swap(a[i],a[min_indx]);
    swaps.push_back({i,min_indx});
    ShiftDown(a,min_indx,n,swaps);
  }
}

void ConvertToHeap(int a[],int n){
  vector<pair<int,int>>swaps; 
  for(int i =n/2;i>=0;i--) ShiftDown(a,i,n,swaps); 
  cout<<swaps.size()<<'\n';
  for(auto &tuple : swaps) cout<<tuple.first<<' '<<tuple.second<<'\n';
}

int main(){
  FastIO; 
  int n;  
  cin>>n;
  int a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  ConvertToHeap(a,n);
  return 0;
} 
