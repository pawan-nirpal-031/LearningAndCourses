#include <iostream>
#include <vector> 
#include <map> 
#include <algorithm>
#include "AlgorithmicModel.h"
using namespace std; 

QLearning::QLearning(const int &NumStates,const int &NumActions,const int &Range): StateSize(NumStates),ActionSize(NumActions),Range(Range){
    try{
        if(StateSize>0 and ActionSize>0){
            #if Dbg
                cout<<"Constructer done...\n"<<endl;
            #endif
            Init = true; 
        }else{
            throw -1;
        }
    }catch(exception e){
        cerr<<e.what()<<"\n"<<endl;
    }
} 

vector<int> QLearning::IndexFromMulti(int oneDimIndx, int HalfRange, int Depth){
    vector<int>Index(Depth,0);
    for(int i =0;i<Depth;i++){
        Index[i] = oneDimIndx%HalfRange;
        oneDimIndx/=HalfRange;
    }
    return Index;
}
