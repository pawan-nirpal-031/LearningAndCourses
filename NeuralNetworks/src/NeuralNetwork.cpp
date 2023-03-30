#include "../include/NeuralNetwork.h"
#include <assert.h>
using namespace std;

NeuralNetwork::NeuralNetwork(vector<int> &Topology){
    this->Topology = Topology;
    TopologySize = Topology.size();
    for(int i =0;i<TopologySize;i++){
        Layer *L = new Layer(Topology[i]);
        this->Layers.push_back(L);
    }
    for(int i =0;i<TopologySize-1;i++){
        Matrix *m = new Matrix(Topology[i],Topology[i+1],1);
        WeightMatrices.push_back(m);
    }
}

void NeuralNetwork::setCurrentInput(vector<double> &Input){
    this->Input = Input;
    assert(Layers[0]->getNumberOfNeurons()==Input.size() and "Input layer size not matching given input list");
    for(int i =0;i<Input.size();i++){
        Layers[0]->setNeuronValue(i,Input[i]);
    }
}

void NeuralNetwork::printToConsole(){
    for(int i =0;i<TopologySize;i++){
        cout<<"Layer "<<i<<endl;
        if(i==0){
            Matrix m = this->Layers[0]->matrixifyValues();
            m.printToConsole();
            continue;
        }
        Matrix m = this->Layers[i]->matrixifyActivatedValues();
        m.printToConsole();
    }
}