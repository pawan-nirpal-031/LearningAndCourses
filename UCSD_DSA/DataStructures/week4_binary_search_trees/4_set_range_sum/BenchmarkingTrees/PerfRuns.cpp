#include <iostream> 
#include <fstream> 
#include <vector> 
#include <cstdlib>
#include <sstream>
#include <set>
#include <string>
using namespace std;

void ResetBenchMarkingLogNum(int &logNum){
    logNum = 0;
}

class Logger{
public: 
    int logNum,numNodes; 
    ofstream LogWriter;
    Logger(int log,int Nodes){
        logNum = log;
        numNodes = Nodes;
        LogWriter.open(to_string(log)+"Log.log");
        LogWriter<<" Nodes : "<<Nodes<<'\n';
    } 
    void Write(string &msg){
        LogWriter<<": "<<msg<<'\n';
    }
}; 

class QueryWriter{
public: 
    int logNum,numNodes;
    ofstream Querywrite;
    QueryWriter(int log,int Nodes){
        logNum = log;
        numNodes = Nodes; 
        Querywrite.open(to_string(log)+"Query.txt"); 
    }
    void Write(string &msg){
        Querywrite<<": "<<msg<<'\n';
    }
};


int NodeToInsert(set<int>&Cache,int NumNodes){
    int candidate = 1 + rand()%NumNodes; 
    if(Cache.find(candidate)==Cache.end()){
        Cache.insert(candidate);
        return candidate;
    }
    int newCand = 1 + rand()%NumNodes; 
    while(Cache.find(newCand)!=Cache.end()){
        newCand = 1 + rand()%NumNodes; 
    }
    Cache.insert(newCand);
    return newCand;
}

void BenchmarkQueryBuilder(Logger &Log, int NumNodes=0){// insert (i), delete (d), search (s)
    if(NumNodes==0){
        string msg = "No nodes exiting...";
        Log.Write(msg);
        return;
    }else{
        set<int>Cache;
        int iter =0;
        for(;iter<NumNodes/2;iter++){
            int insertNode = NodeToInsert(Cache,NumNodes); 
            QueryWriter InsertQuery(Log.logNum,NumNodes);
            string msg = "i "+to_string(insertNode);
            InsertQuery.Write(msg);
        }
        for(;iter<NumNodes;iter++){// searches
            string msg = "s "+to_string(1+rand()%NumNodes);
            QueryWriter(Log.logNum,NumNodes).Write(msg);
        }
    }
}

void BenchmarkRun(Logger &Log, int NumNodes=0){

}

template <class T>
T ParseString(const std::string& s){
  T out;
  std::stringstream ss(s);
  ss >> out;
  return out;
}



int main(int ArgCount, char *Arguments[]){
    ifstream fin("Lognum.txt"); 
    int logNum; 
    fin>>logNum;
    fin.close();
    int NumberOfNodes = ParseString<int>(Arguments[3]); 
    Logger Log(logNum,NumberOfNodes); 
    string arg1 = static_cast<string>(Arguments[1]);
    if(arg1=="buildQuries=1"){
        cout<<"building quries ...\n";
        BenchmarkQueryBuilder(Log,NumberOfNodes);
    }
   // if(Arguments[2]=="runBenchmark=1") BenchmarkRun();
    logNum++;
    ofstream fout("Lognum.txt");  
    fout<<logNum;
    fout.close();
    fin>>logNum;
    return 0;
}
//  buildQuries=0/1 runBenchmark=0/1