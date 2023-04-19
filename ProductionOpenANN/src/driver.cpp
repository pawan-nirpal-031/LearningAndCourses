#include <iostream> 
#include <vector>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <ostream>
#include <time.h>
#include "../include/NeuralNetwork.h"
using namespace std;

int main(int argc,char **argv){
    vector<double> input = {0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,-0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578,0.1112,0.256,0.578};
    vector<double> target = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.10};
    double learRate = 0.05;
    double momentum = 1;
    double bias = 1;
    vector<int>topology = {40,12,10,8,7,12,10};
    NeuralNetwork learner(topology,2,3,1,0.05,1);
    learner.train(input,target,bias,learRate,momentum,10000);
    return 0;
}