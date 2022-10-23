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
#define Status(b) (cout<<(b?"1\n":"0\n"));
#define Debug 0


int cache[22][32][32][32];

int numcalls = 0; 


bool isSplitPossible(int a[],int i,int s1,int s2,int s3,int tar){ 
  if(s1>tar or s2>tar or s3>tar) return 0;
  if(i==-1) return (s1==s2 and s2==s3);
  if(cache[i][s1][s2][s3]>-1) return cache[i][s1][s2][s3];
  bool ans = isSplitPossible(a,i-1,s1+a[i],s2,s3,tar)
          or isSplitPossible(a,i-1,s1,s2+a[i],s3,tar)
          or isSplitPossible(a,i-1,s1,s2,s3+a[i],tar);
  numcalls++;
  return cache[i][s1][s2][s3] = ans;
}

void solve(){
  int n;
  cin>>n; 
  int a[n];
  int sum =0;
  for(int &x : a){
    cin>>x; 
    sum+=x;
  }
  if(sum%3!=0){
    Status(0);
    return;
  }
  for(int i =0;i<22;i++){
    for(int j =0;j<32;j++){
      for(int k =0;k<32;k++){
        for(int l =0;l<32;l++) cache[i][j][k][l] = -1;
      }
    }
  }
  int tar = sum/3;
  Status(isSplitPossible(a,n-1,0,0,0,tar));
} 



int main(){
  FastIO; 
  solve();
  return 0;
} 

