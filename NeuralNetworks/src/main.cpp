#include <chrono>
#include <iomanip>
#include "../include/Neuron.h"
#include "../include/Matrix.h"
#include "../include/NeuralNetwork.h"
#define PerfMode 1
using namespace std; 
using namespace chrono;


int main(int Argc,char **Argv){
    #if PerfMode
        auto start = high_resolution_clock::now();
    #endif
    
    vector<double>input = {1,0,1};
    vector<int>topology = {3,2,1};
    NeuralNetwork nn(topology);
    nn.setCurrentInput(input);
    nn.feedForwad();
    nn.printToConsole();
    #if PerfMode
        auto stop = high_resolution_clock::now();
        double time_taken =duration_cast<nanoseconds>(stop - start).count();
        cout << "Time taken by program is : " <<fixed<< time_taken << setprecision(9)<<" nanoseconds";
    #endif
    return 0;
}