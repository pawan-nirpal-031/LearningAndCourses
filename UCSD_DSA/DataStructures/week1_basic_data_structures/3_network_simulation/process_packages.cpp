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


void WriteTests(){
  ofstream fout("test1.txt"); 
  int buff,pkts; 
  buff = 5+rand()%3; 
  pkts = 6+rand()%3; 
  fout<<buff<<' '<<pkts<<'\n';
  int prev = 0;
  for(int i =0;i<pkts;i++){
    if(i==0){
      fout<<prev<<" "<<rand()%4<<'\n';
    }else{
      int curr = prev + rand()%4; 
      fout<<curr<<" "<<rand()%4<<'\n';
      prev = curr;
    }
  }
  fout.close(); 
}

struct packet{
  int arrival,burst;
  packet(int at,int bt){
    arrival = at; 
    burst = bt;
  }
  packet(){
    arrival = burst = -1;
  }
};


void solve(){
  int buffer,packets; 
  cin>>buffer>>packets;
  int time = 0;  
  packet stream[packets];
  for(int i =0;i<packets;i++){
    int at,bt; 
    cin>>at>>bt; 
    stream[i].arrival = at; 
    stream[i].burst = bt;
  }
  queue<packet>processing; 
  int strm = 0; 
  while(strm<packets){
    packet &nxt = stream[strm];
    if(nxt.arrival<=time and processing.size()>=buffer){
      cout<<-1<<'\n';
      strm++; 
      continue;
    }
    assert(processing.size()<buffer);
    processing.push(nxt); 
    packet &head = processing.front(); 
    if(head.arrival>time) time = head.arrival; 
    cout<<time<<'\n';
    time+=head.burst;
    processing.pop();
    for(int curr = strm;curr<packets;curr++){
      if(stream[curr].arrival<=time and processing.size()<buffer) processing.push(stream[curr]); 
      else break;
    }
  }
}

int main(){
  FastIO; 
  solve();
  return 0;
} 

