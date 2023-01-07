#include <bits/stdc++.h>
using namespace std;

int64_t Mod = 1000000007;
int64_t prime1 = Mod; // used for computing primary hash value
int64_t prime2 = Mod+2; // used for computing secondary hash value
int64_t x = 1+rand()%1000000000;


// This answers binary search query, state is used to say if there is a common substring of some lenght k or mid in context of binary search. stindx1 gives the start index in str1 of the common substring, stindx2 gives starting index in str2 of length k/mid. 
struct Query{
    bool state; 
    int stindx1,stindx2;
    Query(){
        state = 0;
        stindx1 = stindx2 = -1;
    }
};

// Computes polynomial hash of a substring with start index si and end index ei. x is global and prime is either prime1 for primary hash, and prime2 for secondary hash of that substring.

int64_t PolynomialHash(const string &str,int64_t prime,int64_t x,int si,int ei){
    int64_t hash_val = 0; 
    for(int i = ei;i>=si;i--) hash_val = (hash_val*x+str[i])%prime;
    return hash_val;
} 

int64_t GetInt(const char x){ // returns ASCII of char x
    return x;
}

/*
    1) precompute len k hashes of both strings using level 2 hashing
    2) precompute primary and secondary hashes of substring s1 using rolling hash, initialized using PolynomialHash function. ( This is done by extracting Polynomial hash of the last substring of length k and using that we compute the hashes in a suffix manner, so Hash[i] stores hash of substring starting at i of len k) 
    3) PowerFactor is used to compute substring hash. Hash of a substring starting at i of a valid len k is given by 
        Hash[i] = (x*Hash[i+1] + int(str[i]) - (x^k)*Hash[i+k])%prime
    store these hashes of len k and get the same primary and secondary hashes of len k and do a lookup if primary hashes match and secondary hashes match for any substrings in s1 and s2, we have a Query to return. 

*/
Query GetCommonSubstrLenkQuery(int k,const string &s1,const string &s2){
    int l1 = s1.length();
    int l2 = s2.length();
    // Stores Substring hashes, S1PHash[i] stores the primary hash of string s1 (computed using prime1) of len k starting at i, S1SHash[i] stores the secondary hash of string s1 of len k starting at index i. And the same for s2 hashes. 
    vector<int64_t>S1PHash(l1+1,0),S1SHash(l1+1,0),S2PHash(l2+1,0),S2SHash(l2+1,0);
    S1PHash[l1-k] = PolynomialHash(s1,prime1,x,l1-k,l1-1); // Get the primary polynomial hash of the last substring of len k of s1
    S1SHash[l1-k] = PolynomialHash(s2,prime2,x,l1-k,l1-1);  // Get the secondary polynomial hash of the last substring of len k of s1
    int64_t PowFactor1 = 1; // (x^k)%prime1 
    int64_t PowFactor2 = 1; // (x^k)%prime2
    for(int i =0;i<k;i++){
        PowFactor1 = (PowFactor1 * x)%prime1;
        PowFactor2 = (PowFactor2 * x)%prime2;
    }
    for(int i = l1-k-1;i>=0;i--){
        // compute primary and secondary hashes of string s1 starting at i using the hash of substring stored at i+1
        S1PHash[i] = (x*S1PHash[i+1] + GetInt(s1[i]) - PowFactor1*(S1PHash[i+k]))%prime1; 
        S1SHash[i] = (x*S1SHash[i+1] + GetInt(s1[i]) - PowFactor2*(S1SHash[i+k]))%prime2; 
    }
    unordered_multimap<int64_t,int>S1PCache,S1SCache; // using hash tables for quick lookup 
    for(int i =0;i<=l1-k;i++){
        S1PCache.insert(make_pair(S1PHash[i],i));
        S1SCache.insert(make_pair(S1SHash[i],i));
    }
    S2PHash[l2-k] = PolynomialHash(s2,prime1,x,l2-k,l2-1); // Get the primary polynomial hash of the last substring of len k of s2
    S2SHash[l2-k] = PolynomialHash(s2,prime2,x,l2-k,l2-1);// Get the secondary polynomial hash of the last substring of len k of s2
    for(int i = l2-k-1;i>=0;i--){
        // compute primary and secondary hashes of string s2 starting at i using the hash of substring stored at i+1
        S2PHash[i] = (x*S2PHash[i+1] + GetInt(s2[i]) - PowFactor1*(S2PHash[i+k]))%prime1; 
        S2SHash[i] = (x*S2SHash[i+1] + GetInt(s2[i]) - PowFactor2*(S2SHash[i+k]))%prime2; 
    }
    Query answer;
    for(int i =0;i<=l2-k;i++){
        auto PHashIt = S1PCache.find(S2PHash[i]); // check If primary hash of s2 starting at i found in s1
        auto SHashIt = S1SCache.find(S2SHash[i]);  // check If secondary hash of s2 starting at i found in s1
        if(PHashIt!=S1PCache.end() and SHashIt!=S1SCache.end()){
            if(PHashIt->first==S2PHash[i] and SHashIt->first==S2SHash[i]){
                answer.state = 1; 
                answer.stindx1 = PHashIt->second; // start index of the common substring in s1
                answer.stindx2 = i; // start index of the common substring in s2
            }   
        }
    }
    return answer;
}

/*
    Get The suffix hash of all substrings of len k/mid, store all len k hashes of s1 in a hash table, 
    and go through each substring of len k of s2 and see if the hashes is found.
*/
void Solve(const string &s1,const string &s2){
    int l1 = s1.length();
    int l2 = s2.length();
    int low = 0;
    int high = min(l1,l2);
    int str1indx,str2indx,len;
    str1indx = str2indx = len = -1;
    while(low+1<high){
        int mid = (low+high)/2;
        Query local = GetCommonSubstrLenkQuery(mid,s1,s2);
        if(local.state){
            low = mid;
            len = mid;
            str1indx = local.stindx1;
            str2indx = local.stindx2;
        }else{
            high = mid;
        }
    } 
    if(str1indx==-1 or str2indx==-1 or len==-1){
        cout<<0<<' '<<1<<' '<<0<<'\n';
        return;
    }
    cout<<str1indx<<' '<<str2indx<<' '<<len<<'\n';
}

int main(){
  ifstream fin("input.txt");
  vector<string>data; 
  string tmp;
  while(fin>>tmp){
    data.push_back(tmp);
  }
  for(int i =0;i<data.size();i+=2){
    string &s1 = data[i];
    string &s2 = data[i+1];
    Solve(s1,s2);
  }
  return 0;
} 
