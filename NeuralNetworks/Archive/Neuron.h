#pragma once 
#include <stdlib.h>
#include <iostream> 
#include <vector>
using namespace std;

class Neuron{
protected:
    double outputValue;
    double error;
    double sensibilty;
public:
    vector<double>weightsListIn;
    vector<double>weightsListOut; 
    Neuron();
    ~Neuron();
    double initNeuron();
};