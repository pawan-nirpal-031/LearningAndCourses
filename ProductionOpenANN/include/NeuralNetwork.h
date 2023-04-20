#ifndef NEURAL_NET
#define NEURAL_NET 
#define COST_MSE 1

#include <iostream> 
#include <vector>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <ostream>
#include <time.h>
#include <algorithm>
#include <assert.h>
#include "Matrix.h"
#include "Layer.h"

using namespace std;


class NeuralNetwork{
public:
    int topologySize;
    int hiddenActivationType = Relu;
    int outputActivationType = Sigm;
    int costFunctionType = COST_MSE;
    double bais = 1;
    double error = 0.000;
    double momentum;
    double learningRate;
    vector<int> topology;
    vector<Layer*> Layers; 
    vector<Matrix*> weightMatrices;
    vector<Matrix*> gradientMatrices;
    vector<double> input; 
    vector<double> target;
    vector<double> errors;
    vector<double> derivedErrors;

    NeuralNetwork(vector<int> &topo,double bais = 1,double learningRate = 0.05, double momentum = 1);

    NeuralNetwork(vector<int> &topo,int hiddenActivation,int ouputActivation,int costFunctionType,double bais = 1,double learningRate = 0.05, double momentum = 1);

    void setCurrentInput(vector<double> &input){ this->input = input;}
    void setCurrentTarget(vector<double> &target){ this->target = target;}
    void feedforward();
    void backpropagation();
    void setErrors();
    vector<double> getActivatedVals(int layrIndx){ return Layers[layrIndx]->getActivatedVals();}
    Matrix *getNeuronMatrix(int indx){ return Layers[indx]->matrixifyValues();}
    Matrix *getActivatedNeuronMatrix(int indx){ return Layers[indx]->matrixifyActivatedValues();}
    Matrix *getDerivedNeuronMatrix(int indx){ return Layers[indx]->matrixifyDerivedValues();}
    // return the pointer to orignal matrix on heap not a copy
    Matrix* getWeightMatrix(int indx){ return weightMatrices[indx];}
    void setNeuronValue(int layerIndx,int neuronIndx,double val){ Layers[layerIndx]->setValue(neuronIndx,val);}
    void trainEpochs(vector<double> &input,vector<double>&target,double bais,double learningRate,double momentum,int epochs=100);
    void train(vector<double> &input,vector<double>&target,double bais,double learningRate,double momentum);
    void stateValidator();
    void printTotalError();
    void printOutputLayer();
    void printNetworkArchitecture();
private:
    void setMeanSqauredErrors();
};

#endif