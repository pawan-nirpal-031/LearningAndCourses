#pragma once 
#include "Layer.h"

class InputLayer : public Layer{
private:

public:
    InputLayer();
    ~InputLayer();
    InputLayer& initLayer(InputLayer &inputLayer);
    void printLayer(InputLayer &inputLayer);
};

InputLayer& InputLayer::initLayer(InputLayer &inputLayer){
    vector<Neuron> listOfNeurons;
    vector<double> listOfWeightInTmp;
    for(size_t i =0;i<inputLayer.numberOfNueronsInLayer;i++){
        Neuron neuron;
        listOfWeightInTmp.push_back(neuron.initNeuron());
        neuron.weightsListIn = listOfWeightInTmp;
        listOfWeightInTmp.clear();
    }
    inputLayer.neuronList = listOfNeurons;
    return inputLayer;
}

void InputLayer::printLayer(InputLayer &layer){
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
