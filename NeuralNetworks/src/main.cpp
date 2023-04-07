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
    int epochs = 100000;
    vector<int> NumEpochs(epochs);
    vector<double> ErrorPlot(epochs);
    for(int i =0;i<epochs;i++){
        cout<<i<<" ";
        nn.feedForwad();
        nn.setErrors();
        NumEpochs[i] = i;
        double totalErr = nn.getTotalError();
        ErrorPlot.push_back(totalErr);
        cout<<totalErr<<"\n";
        nn.backpropagation();
        //cout<<"Output : "<<"\n";
       // nn.printTargetToConsole();
    }
    #if PerfMode
        auto stop = high_resolution_clock::now();
        double time_taken =duration_cast<nanoseconds>(stop - start).count();
        cout<<fixed<< time_taken << setprecision(9)<<" ";
    #endif
    return 0;
}