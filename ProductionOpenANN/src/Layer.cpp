#include "../include/Layer.h"

int Layer::getNumNeurons() const{
    assert(neurons.size()==size and "Neuron list and size not the same");
    return size;
}

vector<double> Layer::getActivatedVals(){
    vector<double> actVals;
    for(int i=0;i<neurons.size();i++)
        actVals.push_back(neurons[i]->getActivatedValue());
    return actVals;
}

void Layer::setNeurons(vector<Neuron*> nlist){// check if nlist can be passed via refrence 
    for(auto N : neurons){
        if(N==nullptr) continue;
        delete(N);
    }
    neurons.clear();
    neurons = nlist;
}

Matrix* Layer::matrixifyValues(){
    Matrix *m = new Matrix(1,getNumNeurons(),0);
    for(int i =0;i<neurons.size();i++){
        m->setValue(0,i,neurons[i]->getValue());
    }
    return m;
}

Matrix* Layer::matrixifyActivatedValues(){
    Matrix *m = new Matrix(1,getNumNeurons(),0);
    for(int i =0;i<neurons.size();i++){
        m->setValue(0,i,neurons[i]->getActivatedValue());
    }
    return m;
}

Matrix* Layer::matrixifyDerivedValues(){
    Matrix *m = new Matrix(1,getNumNeurons(),0);
    for(int i =0;i<neurons.size();i++){
        m->setValue(0,i,neurons[i]->getDerivedValue());
    }
    return m;
}

Layer::Layer(int size){
    this->size = size;
    for(int i =0;i<size;i++){
       Neuron *n = new Neuron(0.00000000);
       neurons.push_back(n);
    }
}

Layer::Layer(int size,int activationType){
    this->size = size;
    for(int i =0;i<size;i++){
       Neuron *n = new Neuron(0.00000000,activationType);
       neurons.push_back(n);
    }
}

void Layer::setValue(int nIndx,double Value){
    assert(nIndx<neurons.size() and "neuron index out of bounds!");
    neurons[nIndx]->setVal(Value);
}