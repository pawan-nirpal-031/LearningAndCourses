#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;

ll getcom(ll m){
  return ((m*(m+1))>>1);
}

int get_largest_smaller_or_equal(ll n){
  int l = 0; 
  int h = 100000; 
  while(l+1<h){
    int m = ((l+h)>>1);
    ll sum_m = getcom(m);
    if(sum_m==n) return m;
    else if(n<sum_m) h = m;
    else l = m;
  }
  if(n<=getcom(l)) return l;
  return h;
}



void optimal_summands(ll n){
  int k = get_largest_smaller_or_equal(n);
  if(n<getcom(k)) k--; 
  cout<<k<<'\n';
  for(int i = 1;i<=k-1;i++) cout<<i<<' '; 
  cout<<k+n-getcom(k);
}

int main() {
  int n; 
  cin>>n;
  optimal_summands(n);
}
