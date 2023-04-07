#include <chrono>
#include <iomanip>
#include "../include/Neuron.h"
#include "../include/Matrix.h"
#include "../include/NeuralNetwork.h"
#define PerfMode 0
using namespace std;
using namespace chrono;


int main(int Argc,char **Argv){
    #if PerfMode
        auto start = high_resolution_clock::now();
    #endif
    
    vector<double>input = {1,0,1};
    vector<int>topology = {3,2,3};
    NeuralNetwork nn(topology);
    nn.setCurrentInput(input);
    nn.setCurrentTarget(input); 
    // Training process 
    int epochs = 1000;
    for(int i =0;i<epochs;i++){
        cout<<i<<" ";
        nn.feedForwad();
        nn.setErrors();
        double totalErr = nn.getTotalError();
        cout<<totalErr<<"\n";
        nn.backpropagation();
        //cout<<"Output : ";
        //nn.printTargetToConsole();
    }
    #if PerfMode
        auto stop = high_resolution_clock::now();
        double time_taken =duration_cast<nanoseconds>(stop - start).count();
        cout<<fixed<< time_taken << setprecision(9)<<" ";
    #endif
    return 0;
}