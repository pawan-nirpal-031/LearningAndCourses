#pragma once 
#include "Neuron.h"

class Layer{
protected:
    vector<Neuron>neuronList;
    size_t numberOfNueronsInLayer;
public:
    Layer();
    ~Layer();
};