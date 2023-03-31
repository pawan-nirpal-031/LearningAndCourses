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
    #if PerfMode
        auto stop = high_resolution_clock::now();
        double time_taken =duration_cast<nanoseconds>(stop - start).count();
        cout<<fixed<< time_taken << setprecision(9)<<" ";
    #endif
    return 0;
}