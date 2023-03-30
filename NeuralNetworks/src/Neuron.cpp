#include "../include/Neuron.h"

Neuron::Neuron(double Value){
    this->Value = Value;
    activate();
    derive();
}

void Neuron::activate(){
    this->ActivatedValue = (this->Value)/(1+abs(this->Value));
}

void Neuron::derive(){
    this->DerivedValue = this->ActivatedValue*(1-this->ActivatedValue);
}
