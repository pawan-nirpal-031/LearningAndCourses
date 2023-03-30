#pragma once 
#include "Layer.h"

class OutputLayer : public Layer{
private:

public:
    OutputLayer();
    ~OutputLayer();
    OutputLayer& initLayer(OutputLayer &outputLayer);
    void printLayer(OutputLayer &outputLayer);
};

OutputLayer& OutputLayer::initLayer(OutputLayer &outputLayer){
    vector<Neuron> listOfNeurons;
    vector<double> listOfWeightOutTmp;
    for(size_t i =0;i<outputLayer.numberOfNueronsInLayer;i++){
        Neuron neuron;
        listOfWeightOutTmp.push_back(neuron.initNeuron());
        neuron.weightsListIn = listOfWeightOutTmp;
        listOfWeightOutTmp.clear();
    }
    outputLayer.neuronList = listOfNeurons;
    return outputLayer;
}

void OutputLayer::printLayer(OutputLayer &layer){
    cout<<"Input Layer : "<<endl;
    int neurCount = 1;
    for(Neuron &neuron : layer.neuronList){
        cout<<"Neuron : "<<neurCount<<endl;
        cout<<"Input weights : "<<endl;
        for(auto &wts : neuron.weightsListIn){
            cout<<wts<<" ";
        }
        neurCount++;
        cout<<endl;
    }
}
