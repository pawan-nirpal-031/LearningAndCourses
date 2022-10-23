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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Debug 0

// ofstream fout("call_log_2_random.txt"); 


namespace two_rocks{
  bool cache[11][11];
  bool vis[11][11];

  bool CanWin(int p1,int p2){ 
    if(p1==0 and p2==0){
      vis[0][0] = 1;
      return cache[p1][p2] = 1;
    }
    if(vis[p1][p2]) return cache[p1][p2];
    if(p1+p2<=2){
      if((p1+p2)==1 or (p1==1 and p2==1)){ 
        return cache[p1][p2] = 0;
      }else{
        vis[p1][p2] = 1;
        return cache[p1][p2]=1;
      }
    }
    if(p1==0){
      vis[p1][p2] = 1;
      return cache[p1][p2] = CanWin(0,p2-1);
    }
    if(p2==0){
      vis[p1][p2] = 1;
      return cache[p1][p2] = CanWin(p1-1,0);
    }
    if(p1!=0 and p2!=0){
      bool ch1 = CanWin(p1-1,p2);
      bool ch2 = CanWin(p1,p2-1);
      bool ch3 = CanWin(p1-1,p2-1);
      if(ch1==0 and ch2==0 and ch3==0){
        vis[p1][p2] = 1;
        return cache[p1][p2] = 1;
      }else{
        vis[p1][p2] = 1;
        return cache[p1][p2] = 0;
      }
    }
    return cache[p1][p2];
  }

  void TwoRocks(){
    for(int i =0;i<11;i++) for(int j =0;j<11;j++) vis[i][j] =0;
    Status(CanWin(9,9)); 
    for(int i =0;i<11;i++) cout<<i<<" "; 
    cout<<'\n';
    for(int i =0;i<11;i++){ 
      for(int j =0;j<11;j++){
        if(j==0) cout<<i<<" ";
        cout<<cache[i][j]<<" ";
      } 
      cout<<'\n';
    }
  }
}

namespace three_rocks{
  bool cache[11][11];
  bool vis[11][11];
  
  bool CanWin(int p1,int p2){ 
    if(p1==0 and p2==0){
      vis[p1][p2] =1; 
      return cache[p1][p2] = 0;
    } 
    if(vis[p1][p2]) return cache[p1][p2];
    if(p1+p2<=4){
      vis[p1][p2] = 1;  
      if(p1+p2<=3){
        return cache[p1][p2] = 0; 
      }else{
        return cache[p1][p2] = 1;
      }
    }  
    if(p1==0){
      vis[p1][p2] = 1;
      bool ch1 = CanWin(0,p2-1);
      bool ch2 = CanWin(0,p2-2);
      bool ch3 = CanWin(0,p2-3); 
      if(ch1==0 and ch2==0 and ch3==0) return cache[p1][p2] = 1;
      else return cache[p1][p2] = 0;
    }
    if(p2==0){
      vis[p1][p2] = 1;
      bool ch1 = CanWin(p1-1,0);
      bool ch2 = CanWin(p1-2,0);
      bool ch3 = CanWin(p1-3,0);
      if(ch1==0 and ch2==0 and ch3==0) return cache[p1][p2] = 1;
      else return cache[p1][p2] = 0;
    }
    if(p1>0 and p2>0){ 
      vis[p1][p2] = 1;
      bool c1 = CanWin(p1,p2-1); 
      bool c2 = CanWin(p1,p2-2); 
      bool c3 = CanWin(p1,p2-3);
      bool c4 = CanWin(p1-1,p2);
      bool c5 = CanWin(p1-2,p2);
      bool c6 = CanWin(p1-3,p2);
      bool c7 = CanWin(p1-1,p2-1);
      bool c8 = CanWin(p1-2,p2-1);
      bool c9 = CanWin(p1-1,p2-2); 
      if(c1==0 and c2==0 and c3==0 and c4==0 and c5==0 and c6==0 and c7==0 and c8==0 and c9==0){
        return cache[p1][p2] = 1;
      }else return cache[p1][p2] = 0;
    }
    return cache[p1][p2];
  }

  void ThreeRocks(){
    for(int i =0;i<11;i++) for(int j =0;j<11;j++) vis[i][j] =0;
    Status(CanWin(10,9)); 
    for(int i =0;i<11;i++) cout<<i<<" "; 
    cout<<'\n';
    for(int i =0;i<11;i++){ 
      for(int j =0;j<11;j++){
        if(j==0) cout<<i<<" ";
        cout<<cache[i][j]<<" ";
      } 
      cout<<'\n';
    }
  }
}


int main(){
  FastIO; 
  three_rocks::ThreeRocks();
  return 0;
} 
