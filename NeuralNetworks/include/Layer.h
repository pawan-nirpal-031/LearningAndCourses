#ifndef LAYER_H 
#define LAYER_H 

#include "Neuron.h"
#include "Matrix.h"
using namespace std; 

class Layer{
private:
    int size; 
    vector<Neuron*> neuronsList; 
public: 
    Layer(int size);
    void setNeuronValue(int i,double Value);
    double getNeuronValue(int i);
    double getNeuronActivatedValue(int i);
    double getNeuronDerivedValue(int i);
    int getNumberOfNeurons(){ return size;}
    // represnts the layer Values in a Matrix form
    Matrix matrixifyValues();
    Matrix matrixifyActivatedValues();
    Matrix matrixifyDerivedValues();
};

#endif