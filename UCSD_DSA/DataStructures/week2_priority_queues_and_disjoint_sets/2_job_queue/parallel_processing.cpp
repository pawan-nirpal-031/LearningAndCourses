#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#define FastIO std::ios_base::sync_with_stdio(false) 
typedef long long int ll;
using namespace std; 

int main() {
  FastIO;
  int workers,jobs; 
  cin>>workers>>jobs; 
  vector<ll>duration(jobs,0);
  for(ll &x : duration) cin>>x; 
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>process_queue; 
  for(int i =0;i<workers;i++) process_queue.push({0,i});  
  int next_free_worker = 0; 
  for(int i =0;i<jobs;i++){
    int burst_time = duration[i];
    int next_free_worker = process_queue.top().second; 
    ll next_free_time = process_queue.top().first; 
    process_queue.pop(); 
    cout<<next_free_worker<<' '<<next_free_time<<'\n'; 
    next_free_time+=burst_time; 
    process_queue.push({next_free_time,next_free_worker});
  } 
  return 0;
}

