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

9 1

1 4  
2 8 
3 5 
6 8 
9 10 
10 12 
11 12 
13 15 
14 15 



*/

bool comp(const pair<int,int> &fir,const pair<int,int> &sec){
  return sec.second>fir.second;
}

int SearchFirstList(vector<pair<int,int>> &segments,int point){
  // search for the first el greater than point
  int high = segments.size();
  int low = -1; 
  while(low+1<high){
    int mid = (low + (high - low)/2);
    if(point<segments[mid].first) high = mid;
    else low = mid;
  }
  return high;
}

int SearchSecondList(vector<pair<int,int>> &segments,int point){
  // search for the last el less than point 
  int high = segments.size();
  int low = -1; 
  while(low+1<high){
    int mid = (low + (high - low)/2);
    if(segments[mid].second>=point) high = mid;
    else low = mid;
  }
  return low;
}

int main(){
  FastIO; 
  int num_segs,num_pts; 
  cin>>num_segs>>num_pts; 
  vector<pair<int,int>>segments(num_segs,{0,0}); 
  vector<pair<int,int>>segments_sec(num_segs,{0,0});
  for(int i =0;i<num_segs;i++){
    cin>>segments[i].first>>segments[i].second; 
    segments_sec[i].first = segments[i].first; 
    segments_sec[i].second = segments[i].second; 
  }
  sort(segments.begin(),segments.end()); 
  sort(segments_sec.begin(),segments_sec.end(),comp);
  for(int q = 0;q<num_pts;q++){
    int point; 
    cin>>point; 
    int high = SearchFirstList(segments,point);
    int lower = SearchSecondList(segments_sec,point); 
    int num_lines = high - lower - 1; 
    cout<<(num_lines<0?0:num_lines)<<" ";
  }
  return 0;
} 
