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
#define Debug 0

ull Prime = Mod;
ll x = 35;

ll getInt(const char v){
	return v;
}

ll power(ll x,ll a){
    if(a==0) return 1;
    if(a==1) return a; 
    ll half = power(x,a/2); 
    ll precom = (half%Prime * half%Prime)%Prime;
    return ((a&1)?(precom*a)%Prime:precom);
}

int hasUtmostKMisMatches(string &text,string &pattrn,int i,int left,int right,vector<ll>&hashTextArray,vector<ll>&hashPattrnArray, int k){ 
    if(left>right) return 0; 
    int tstlen = right-left+1; 
    ll y = power(x,tstlen);
    ll textSubstrHash = (Prime + hashTextArray[i+tstlen] - (y * hashTextArray[i]%Prime))%Prime; 
    ll pattrnSubstrHash = (Prime + hashPattrnArray[left+tstlen] - (y * hashPattrnArray[left])%Prime)%Prime; 
    if(textSubstrHash==pattrnSubstrHash) return 0;
    int mid = left + (tstlen-1)/2; 
    int mismatches = (text[i+mid]!=pattrn[mid]); 
    int leftMismatches = hasUtmostKMisMatches(text,pattrn,i,left,mid-1,hashTextArray,hashPattrnArray, k-mismatches); 
    int rightMismatches = hasUtmostKMisMatches(text,pattrn,i,mid+1,right,hashTextArray,hashPattrnArray, k-mismatches); 
    mismatches += leftMismatches + rightMismatches;
    if (mismatches > k) {
       return k+1;
    }
    return mismatches;
}


void preComputePrefixHashes(string &str,vector<ll>&hashArray){
    for(int i =1;i<=str.length();i++) hashArray[i] = (x*hashArray[i-1] + getInt(str[i-1]))%Prime;
}

void solve(int k,string &text,string &pattern){
	int texlen = text.length(); 
	int pattlen = pattern.length(); 
	assert(texlen>=pattlen);
	vector<int>mismatchList;
    vector<ll>prefixHashesText(texlen+1,0);
    vector<ll>prefixHashesPattrn(pattlen+1,0);
    preComputePrefixHashes(text,prefixHashesText);
    preComputePrefixHashes(pattern,prefixHashesPattrn);
	for(int i =0;i<=texlen-pattlen;i++){
		if(hasUtmostKMisMatches(text,pattern,i,0,pattlen-1,prefixHashesText,prefixHashesPattrn,k)<=k) mismatchList.push_back(i);
	}	
	cout<<mismatchList.size()<<" ";
	for(int &x : mismatchList) cout<<x<<' '; 
    cout<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		solve(k,t,p);
	}
}
