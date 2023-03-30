#include "../include/NeuralNetwork.h"
#include "../infrastructure/utils/MatrixToVector.h"
#include "../infrastructure/utils/MatrixMultiplication.h"
#include <assert.h>
using namespace std;

NeuralNetwork::NeuralNetwork(vector<int> &Topology){
    this->Topology = Topology;
    TopologySize = Topology.size();
    for(int i =0;i<TopologySize;i++){
        Layer *L = new Layer(Topology[i]);
        this->Layers.push_back(L);
    }
    for(int i =0;i<TopologySize-1;i++){
        Matrix *m = new Matrix(Topology[i],Topology[i+1],1);
        WeightMatrices.push_back(m);
    }
}

void NeuralNetwork::setCurrentInput(vector<double> &Input){
    this->Input = Input;
    assert(Layers[0]->getNumberOfNeurons()==Input.size() and "Input layer size not matching given input list");
    for(int i =0;i<Input.size();i++){
        Layers[0]->setNeuronValue(i,Input[i]);
    }
}

void NeuralNetwork::printToConsole(){
    for(int i =0;i<TopologySize;i++){
        cout<<"Layer "<<i<<endl;
        cout<<"===================\n";
        if(i<Layers.size()-1){
            cout<<"Weight matrix at : "<<i<<endl;
            WeightMatrices[i]->printToConsole();
        }
        cout<<"===================\n";
        if(i==0){
            Matrix m = this->Layers[0]->matrixifyValues();
            m.printToConsole();
            continue;
        }
        Matrix m = this->Layers[i]->matrixifyActivatedValues();
        m.printToConsole();
    }
}

Matrix NeuralNetwork::getNeuronMatrix(int Indx){
    Matrix nMat = Layers[Indx]->matrixifyValues();
    return nMat;
}

Matrix NeuralNetwork::getActivatedNeuronMatrix(int Indx){
    Matrix aMat = Layers[Indx]->matrixifyActivatedValues();
    return aMat;
}

Matrix NeuralNetwork::getDerivedNeuronMatrix(int Indx){
    Matrix dMat = Layers[Indx]->matrixifyDerivedValues();
    return dMat;
}

Matrix NeuralNetwork::getWeightMatrix(int Indx){
    assert(Indx<TopologySize-1 and "Invalid weight matrix access");
    Matrix *wtMat = WeightMatrices[Indx];
    assert(wtMat!=nullptr and "Layer missing weight matrix");
    return *wtMat;
}

void NeuralNetwork::setNeuronValue(int layerIndx,int neuronIndx,double Value){
    Layers[layerIndx]->setNeuronValue(neuronIndx,Value);
}

void NeuralNetwork::feedForwad(){
    int topologySize = Layers.size()-1;
    for(int i =0;i<topologySize;i++){
        Matrix a = (i==0?getNeuronMatrix(i):getActivatedNeuronMatrix(i));
        Matrix b = getWeightMatrix(i);
        // get the product of value/activation and weight matrix
        Matrix *c = utils::multiply(a,b);
        // propagate the result as the Value to next layer
        for(int cIndx = 0;cIndx<c->getNumCols();cIndx++){
            setNeuronValue(i+1,cIndx,c->getValue(0,cIndx));
        }
    }
}
