#pragma once 
#include "Neuron.h"

class Layer{
protected:
public:
    vector<Neuron>neuronList;
    size_t numberOfNueronsInLayer;
    Layer();
    ~Layer();
};