#include "../include/NeuralNetwork.h"

void NeuralNetwork::train(vector<double> &input,vector<double>&target,double bais,double learningRate,double momentum,int epochs){
    this->learningRate = learningRate;
    this->bais = bais;
    this->momentum = momentum;
    setCurrentInput(input);
    setCurrentTarget(target);
    for(int e =0; e< epochs;e++){
        printTotalError();
        feedforward();
        setErrors();
        backpropagation();
    }
}