#ifndef NEURAL_NETWORK_H 
#define NEURAL_NETWORK_H 
#include "Matrix.h"
#include "Layer.h"
using namespace std; 

class NeuralNetwork{
private: 
    // list of values where each value is the size of each layer/ number of neurons in each layer
    vector<int>     Topology;
    vector<Layer*>  Layers;
    // Number of WeightMatrices would be topologySize - 1, from layer i-1 to i 
    vector<Matrix*> WeightMatrices;
    // Number of layers 
    int             TopologySize;
    vector<double>  Input;
    // Objective ground truth values, has similar number of Values to output layer
    vector<double>  Target;
    // Total error for the network, sum of all errors out output layer
    double          Error;
    // Error for each neuron in the output layer
    vector<double>  Errors;
    vector<double>  HistoricalErrors;
    vector<Matrix*> Gradients;
public: 
    NeuralNetwork(vector<int> &Topology);
    void setCurrentInput(vector<double> &Input);
    void printToConsole();
    void feedForwad();
    void backpropagation();
    Matrix *getNeuronMatrix(int Indx);
    Matrix *getActivatedNeuronMatrix(int Indx);
    Matrix *getDerivedNeuronMatrix(int Indx);
    Matrix *getWeightMatrix(int Indx);
    void setNeuronValue(int layerIndx,int neuronIndx,double Val);
    double getTotalError(){ return this->Error;}
    vector<double> &getErrorVector(){ return this->Errors;}
    void setErrors();
    double costFunction(double CurrValue,double Target);
    void setCurrentTarget(vector<double>&target);
    void printErrors();
};

#endif