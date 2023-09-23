#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 


int compute(int curr,int n, vector<int> &hist){
    if(hist[curr]>-1) return hist[curr];
    if(curr==n) return hist[curr] = 0;
    if(2*curr<=n) return hist[curr] =  min(1 + compute(curr+1,n,hist),2 + compute(2*curr,n,hist));
    return hist[curr] =  1 + compute(curr+1,n,hist);
}

int main(){
    // s to s+1 takes 1 min
    // s to 2s takes 2 mins
    // min time from 1 to n
    int n; 
    vector<int>history(n+1,-1);
    cin>>n; 
    cout<<compute(1,n,history);
    return 0;
}
