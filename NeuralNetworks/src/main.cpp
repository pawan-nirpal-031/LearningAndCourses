#include <iostream> 
#include "../include/Neuron.h"
using namespace std; 

int main(int Argc,char **Argv){
    Neuron *neuron = new Neuron(1.5);
    neuron->printAllValues();
    return 0;
}