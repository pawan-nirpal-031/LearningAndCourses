#ifndef NEURON_H
#define NEURON_H
#define TanH 1
#define Relu 2 
#define Sigm 3

#include <iostream>
#include <math.h>

class Neuron{
public:
    Neuron(double val);
    Neuron(double val,int activationType);
    void setVal(double val);
    void activate();
    void derive();
    double getValue(){ return value;}
    double getActivatedValue(){ return activatedValue;}
    double getDerivedValue() { return derivedValue;}
private:
    double value;
    double activatedValue;
    double derivedValue;
    // Tanh or Relu or Sigmoid
    int activationType = 3; 
};

#endif