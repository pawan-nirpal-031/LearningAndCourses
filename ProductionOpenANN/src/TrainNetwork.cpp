#include <iostream> 
#include <vector>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <ostream>
#include <time.h>
#include "../include/NeuralNetwork.h"
#include "../include/utils/json.hpp"
#include "../include/utils/DataManager.h"
using namespace std;
using json = nlohmann::json;


int trainingDriver(int argc,char **argv){
    if(argc!=2){
        cout<<"incorrect number of args recived by driver! exiting...\n";
        return -1;
    }
    ifstream configFile(argv[1]);
    string parserStr((istreambuf_iterator<char>(configFile)),istreambuf_iterator<char>());

    auto config = json::parse(parserStr);
    double learRate = config["learningRate"];
    double momentum = config["momentum"];
    double bias = config["bias"];
    vector<int> topology = config["topology"];
    string trainDataFile = config["trainingData"];
    string labelDataFile = config["labelData"];
    int epochs = config["epochs"];
    epochs*=10;
    cout<<"config parsed\n";
    vector<vector<double>> trainData = utils::DataReader().fetchData(trainDataFile);
    cout<<"data parsed\n";
    vector<vector<double>> labels = utils::DataReader().fetchData(labelDataFile);
    cout<<"labels parsed\n";
    NeuralNetwork n(topology,2,3,1,bias,learRate,momentum); 
    for(int tIndx =0;tIndx<trainData.size();tIndx++){
        cout<<"traning on data : "<<tIndx<<"\n";
        n.trainEpochs(trainData[tIndx],labels[tIndx],bias,learRate,momentum,epochs);
        cout<<"printing output for dataset : "<<tIndx<<"\n";
        n.printOutputLayer();
        cout<<"\n\n";
    }
    return 0;
}

int main(int argc,char **argv){
    trainingDriver(argc,argv);
    return 0;
}