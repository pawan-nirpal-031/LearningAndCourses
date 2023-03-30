#ifndef NEURON_H 
#define NEURON_H 

#include <iostream> 
#include <vector> 
#include <math.h>
using namespace std; 

class Neuron{
    // Raw value say 1.5
    double Value; 
    // Normalized value to range [0-1] for learning Non linear functions 
    double ActivatedValue;
    // Approximated derivate of Activatedvalue
    double DerivedValue;


public: 
    Neuron(double Value);
    // Fast sigmoid activation function f(x) = x/(1+|x|), where x is Value and f(x) is Activatedvalue 
    void activate();
    // The derivative is f'(x) = f(x)*(1-f(x)), where f(x) is Activatedvalue and x is Value
    void derive();
    inline double getValue(){ return this->Value;}
    inline double getActivatedValue(){ return this->ActivatedValue;}
    inline double getDerivedValue(){ return this->DerivedValue;}
    inline void printAllValues(){
         cout<<"Value : "<<this->getValue()<<" Activated value : "<<this->getActivatedValue()<<" Derived value : "<<this->getDerivedValue()<<endl;
    }
};

#endif