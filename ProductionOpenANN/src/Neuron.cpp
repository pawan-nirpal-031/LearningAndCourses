#include "../include/Neuron.h"
#include <assert.h>

void Neuron::setVal(double val){
    value = val;
    activate();
    derive();
}

void Neuron::activate(){
    if(activationType==TanH){
        activatedValue = tanh(value);
    }else if(activatedValue==Relu){
        activatedValue = (activatedValue>0?activatedValue:0);
    }else {
        activatedValue = (1/(1+exp(-value)));
    }
}   

void Neuron::derive(){
    if(activationType==TanH){
        derivedValue = (1.0 - (activatedValue*activatedValue));
    }else if(activatedValue==Relu){
        derivedValue = (value>0?1:0);
    }else {
        derivedValue = (activatedValue * (1.0 - activatedValue));
    }
}

Neuron::Neuron(double val){
    setVal(val);
}

Neuron::Neuron(double val,int activationType){
    setVal(val);
    assert(activationType>=1 and activationType<=3 and "Attempt to set an invalid activation type");
    this->activationType = activationType;
}