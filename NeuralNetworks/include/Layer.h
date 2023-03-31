#ifndef LAYER_H 
#define LAYER_H 

#include "Neuron.h"
#include "Matrix.h"
#include <assert.h>
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
    // represnts the layer Values in a Matrix form
    Matrix matrixifyValues();
    Matrix matrixifyActivatedValues();
    Matrix matrixifyDerivedValues();
    vector<Neuron*>& getNeuronList();
    void setNeuronList(vector<Neuron*> &inputList);
    int getNumberOfNeurons(){
        assert(size==neuronsList.size() and "neuron list and size attribute unmatched");
        return size;
    }
};

#endif