#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include "Matrix.h"
#include <iostream>

class Layer{
public:
    Layer(int size);
    Layer(int size,int activationType);
    void setValue(int neuronIndx,double val);
    double getValue(int nIndx){ return neurons[nIndx]->getValue();}
    double getActivatedValue(int nIndx){ return neurons[nIndx]->getActivatedValue();}
    double getDerivedValue(int nIndx){ return neurons[nIndx]->getDerivedValue();}
    Matrix* matrixifyValues();
    Matrix* matrixifyActivatedValues();
    Matrix* matrixifyDerivedValues();
    void setNeurons(vector<Neuron*> nlist);
    vector<double> getActivatedVals();
    int getNumNeurons() const;
    vector<Neuron*> getNeurons() { return neurons;}
private:
    int size;
    vector<Neuron*> neurons;
};

#endif
