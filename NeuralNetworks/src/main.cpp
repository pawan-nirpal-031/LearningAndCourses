#include <iostream> 
#include "../include/Neuron.h"
#include "../include/Matrix.h"
#include "../include/NeuralNetwork.h"
using namespace std; 

int main(int Argc,char **Argv){
    vector<int> topology = {3,2,3};
    vector<double>input = {1.0,0.0,1.0};
    NeuralNetwork nn(topology);
    nn.setCurrentInput(input);
    nn.printToConsole();
    return 0;
}