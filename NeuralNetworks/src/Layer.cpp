#include "../include/Layer.h"
#include <assert.h>

Layer::Layer(int size){
    for(unsigned int i =0;i<size;i++) this->neuronsList.push_back(new Neuron(0.0));
    this->size = size;
}

void Layer::setNeuronValue(int Indx,double Value){
    assert(Indx<size and "Invalid access into layer list");
    assert(neuronsList[Indx]!=nullptr and "No Neuron found at given index");
    neuronsList[Indx]->setValue(Value);
}

double Layer::getNeuronValue(int Indx){
    assert(Indx<size and "Invalid access into layer list");
    assert(neuronsList[Indx]!=nullptr and "No Neuron found at given index");
    return neuronsList[Indx]->getValue();
}

double Layer::getNeuronActivatedValue(int Indx){
    assert(Indx<size and "Invalid access into layer list");
    assert(neuronsList[Indx]!=nullptr and "No Neuron found at given index");
    return neuronsList[Indx]->getActivatedValue();
}

vector<Neuron*>& Layer::getNeuronList(){
    return this->neuronsList;
}

void Layer::setNeuronList(vector<Neuron*> &inputList){
    this->neuronsList = inputList;
}

double Layer::getNeuronDerivedValue(int Indx){
    assert(Indx<size and "Invalid access into layer list");
    assert(neuronsList[Indx]!=nullptr and "No Neuron found at given index");
    return neuronsList[Indx]->getDerivedValue();
}

Matrix* Layer::matrixifyValues(){
    Matrix *Mat = new Matrix(1,this->getNumberOfNeurons(),0);
    for(int i =0;i<size;i++){
        Mat->setValue(0,i,this->getNeuronValue(i));
    }
    return Mat;
}

Matrix* Layer::matrixifyActivatedValues(){
    Matrix *Mat = new Matrix(1,this->getNumberOfNeurons(),0);
    for(int i =0;i<size;i++){
        Mat->setValue(0,i,this->getNeuronActivatedValue(i));
    }
    return Mat;
}

Matrix* Layer::matrixifyDerivedValues(){
    Matrix *Mat = new Matrix(1,this->getNumberOfNeurons(),0);
    for(int i =0;i<size;i++){
        Mat->setValue(0,i,this->getNeuronDerivedValue(i));
    }
    return Mat;
}