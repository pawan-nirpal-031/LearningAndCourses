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

int inv_count = 0;

void combine(int a[],int st,int mid,int end){
  int n = end - st + 1; 
  int temp[n];
  int t =0; 
  int p1 = st; 
  int p2 = mid+1;
  while(p1<=mid and p2<=end){
    if(a[p1]<=a[p2]) temp[t++] = a[p1++];
    else{
      inv_count+=(mid-p1+1);
      temp[t++] = a[p2++];
    }
  }
  if(p1<=mid) while(p1<=mid) temp[t++] = a[p1++];
  if(p2<=end) while(p2<=end) temp[t++] = a[p2++];
  for(int i = 0;i<n;i++) a[st+i] = temp[i];
}

void ms(int a[],int st,int end){
  if(st==end or st>end) return; 
  int mid = (st + (end-st)/2);
  ms(a,st,mid);
  ms(a,mid+1,end);
  combine(a,st,mid,end);
}

int main(){
  FastIO; 
  int n;
  cin>>n; 
  int a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  ms(a,0,n-1);
  cout<<inv_count;
  return 0;
} 
