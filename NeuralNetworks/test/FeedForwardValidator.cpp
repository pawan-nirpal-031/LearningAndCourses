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
    double getValue(){ return this->Value;}
    void setValue(double Value);
    double getActivatedValue(){ return this->ActivatedValue;}
    double getDerivedValue(){ return this->DerivedValue;}
    void printAllValues(){
         cout<<"Value : "<<this->getValue()<<" Activated value : "<<this->getActivatedValue()<<" Derived value : "<<this->getDerivedValue()<<endl;
    }
};

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

void Neuron::setValue(double Value){
    this->Value = Value; 
    activate();
    derive();
}


int main(){
    // (0.978507 | 0.516145)
    Neuron *n = new Neuron(0.978507);
    cout<<n->getActivatedValue();
    cout<<endl;
    Neuron *n1 = new Neuron(0.516145);
    cout<<n1->getActivatedValue();

    /*
        Layer 0
        ===================
        Weight matrix at : 0
        0.555516 0.00661543 
        0.968765 0.868514 
        0.422991 0.50953 
        ===================
        1 0 1 
        Layer 1
        ===================
        Weight matrix at : 1
        0.07237 
        0.153627 
        ===================
        0.494569 0.340433 
        Layer 2
    */
   /*
        ans : 0.494568
              0.340432
        correct
   */
}