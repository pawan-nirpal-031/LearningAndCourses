#include "../include/NeuralNetwork.h"

void NeuralNetwork::setErrors(){
    assert(target.size()!=0 and "no target found!");
    assert((target.size()==Layers[Layers.size()-1]->getNumNeurons()) and "target size and output layer size do not match!");
    switch(costFunctionType){
        case(COST_MSE):{
            setMeanSqauredErrors();
            break;
        };
        default:{
            setMeanSqauredErrors();
        }
    }
}

void NeuralNetwork::setMeanSqauredErrors(){
    int outputLayrIndx = topologySize -1;
    vector<Neuron*> outputNeurons = Layers[outputLayrIndx]->getNeurons();
    error = 0.00;
    for(int i =0;i<target.size();i++){
        double t = target[i];
        double y = outputNeurons[i]->getActivatedValue();
        errors[i] = 0.5*pow(abs(t-y),2);
        derivedErrors[i] = (y-t);
        error+=errors[i];
    }
    stateValidator();
}