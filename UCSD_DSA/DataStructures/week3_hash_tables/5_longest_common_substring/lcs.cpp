#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
using namespace std;

int main(){
    string line ="-1"; 
    vector<string>data;
    while(1){
        cin>>line;
        if(line.compare("-1")==0) break;
        data.push_back(line);
        line = "-1";
    }
    for(int i =0;i<data.size();i+=2){
        cout<<data[i]<<' '<<data[i+1]<<'\n';
    }
    return 0;
}