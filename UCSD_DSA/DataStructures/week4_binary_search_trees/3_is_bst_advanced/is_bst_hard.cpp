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
#define Status(b) (cout<<(b?"CORRECT\n":"INCORRECT\n"));

ll Minimum(pair<ll,ll> &tuple){
  return min(tuple.first,tuple.second);
}

ll Maximum(pair<ll,ll> &tuple){
  return max(tuple.first,tuple.second);
}

pair<ll,ll> IsBinarySearchTreeUtil(const vector<pair<int,int>> &graph,const vector<int> &values,int node,int NodeVal, bool &answer){ // {Min(L),Max(r)}
  assert(node!=-1 and "not a valid node"); 
  int leftNode = graph[node].first; 
  int rightNode = graph[node].second; 
  if(leftNode!=-1 and rightNode!=-1){
    auto leftTuple = IsBinarySearchTreeUtil(graph,values,leftNode,values[leftNode],answer);
    auto rightTuple = IsBinarySearchTreeUtil(graph,values,rightNode,values[rightNode],answer);
    answer = answer and (Maximum(leftTuple)<NodeVal and NodeVal<=Minimum(rightTuple));
    return {min((ll)NodeVal,min(Minimum(leftTuple),Minimum(rightTuple))),max((ll)NodeVal,max(Maximum(leftTuple),Maximum(rightTuple)))};
  }else if(leftNode==-1 and rightNode!=-1){
    auto rightTuple = IsBinarySearchTreeUtil(graph,values,rightNode,values[rightNode],answer);
    answer = answer and (NodeVal<=Minimum(rightTuple));
    return {min((ll)NodeVal,Minimum(rightTuple)),max((ll)NodeVal,Maximum(rightTuple))};
  }else if(leftNode!=-1 and rightNode==-1){
    auto leftTuple = IsBinarySearchTreeUtil(graph,values,leftNode,values[leftNode],answer); 
    answer = answer and (Maximum(leftTuple)<NodeVal);
    return {min((ll)NodeVal,Minimum(leftTuple)),max((ll)NodeVal,Maximum(leftTuple))};
  }
  return {NodeVal,NodeVal};  
}

bool IsBinarySearchTree(const vector<pair<int,int>> &graph,const vector<int> &values,int node){
  bool answer = 1;
  auto tuple = IsBinarySearchTreeUtil(graph,values,node,values[node],answer); 
  return answer;
}

int main(){
  FastIO; 
  int nodes; 
  cin>>nodes; 
  if(nodes==0){
    Status(1);
    return 0;
  }
  vector<pair<int,int>>graph(nodes,{-1,-1});  
  vector<int>values(nodes,0); 
  for(int i =0;i<nodes;i++){
    int val,left,right; 
    cin>>val>>left>>right; 
    values[i] = val; 
    graph[i].first = left; 
    graph[i].second = right;
  }
  Status(IsBinarySearchTree(graph,values,0));
  return 0;
} 
