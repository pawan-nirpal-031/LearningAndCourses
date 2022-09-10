#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));

#define DEBUG 0

int old_optimal_choice(int a,int b){
  string sa = to_string(a);
  string sb = to_string(b);
  if(sa.length()==sb.length()){
    return (a>b?a:b);
  }else{
    if(sa.length()>sb.length()){
       swap(sa,sb);
       swap(a,b);
    }
    assert(sa.length()<sb.length()); 
    if(DEBUG){
      cout<<sa<<' '<<sb<<'\n';
    }
    for(int i =0;i<sa.length();i++){
      if(sa[i]!=sb[i]) return (sa[i]>sb[i]?a:b);
    }
    if(DEBUG) cout<<"Prefix is same\n";
    for(int i = sa.length();i<sb.length();i++){
      if(sb[i]!=sa[0]){
        if(DEBUG){
          cout<<"Point of first diff : "<<sb[i]<<", "<<sa[0]<<'\n';
        }
        return (sb[i]>sa[0]?b:a);
      }
    }
  }
  return a;
}

int optimal_choice(int a,int b){
  string sa = to_string(a);
  string sb = to_string(b); 
  string first = sa+sb; 
  string second = sb+sa; 
  int fir = stoi(first); 
  int sec = stoi(second);
  return (fir>sec?a:b);
}

void solve(){
    int n;
    cin>>n;
    vector<int>single_digit_count(10,0);
    int thousand_count = 0;
    vector<pair<vector<int>,vector<int>>>multi_digits(10,{{},{}});
    multi_digits.resize(10);
    for(int i =0;i<n;i++){
      int x;
      cin>>x; 
      if(x==1000){
        thousand_count+=1; 
      }else if(to_string(x).length()==1){
        single_digit_count[x]+=1;
      }else{
        string sof = to_string(x);
        if(sof.length()==2){
          multi_digits[sof[0]-'0'].first.push_back(x);
        }else{
          multi_digits[sof[0]-'0'].second.push_back(x);
        } 
      }
    } 
    string output; 
    for(int dig = 9;dig>=1;dig--){
      auto &double_digt = multi_digits[dig].first;
      auto &triple_digt = multi_digits[dig].second;
      unsigned int single_cnt = single_digit_count[dig];  
      multiset<int>cache; 
      for(int i =0;i<single_cnt;i++) cache.insert(dig);
      for(int i=0;i<multi_digits[dig].first.size();i++){
        cache.insert(multi_digits[dig].first[i]);
      }
      for(int i =0;i<multi_digits[dig].second.size();i++){
        cache.insert(multi_digits[dig].second[i]);
      }
      while(not cache.empty()){
        auto it = cache.begin();
        int optimal = 1000;
        for(auto &x : cache){
          optimal = optimal_choice(optimal,x);
        }
        auto opt_it = cache.find(optimal);
        output+=to_string(optimal);
        cache.erase(opt_it);
      }
    }
    for(int i =0;i<thousand_count;i++) output+=to_string(1000); 
    cout<<output<<'\n';
}



int main(){
  FastIO;
  int t = 1;
  //cin>>t; 
  while(t--) solve();   
  
  return 0;
} 
