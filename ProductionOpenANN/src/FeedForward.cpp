#include "../include/NeuralNetwork.h"
#include "../include/utils/Math.h"


void NeuralNetwork::feedforward(){
    Matrix *neuronMatrixCurrLayer = nullptr;
    Matrix *weightMatrix = nullptr;
    Matrix *neuronMatrixNextLayer = nullptr;

    for(int i =0;i<topologySize-1;i++){
        neuronMatrixCurrLayer = (i==0?getNeuronMatrix(i):getActivatedNeuronMatrix(i));
        weightMatrix = weightMatrices[i];
        neuronMatrixNextLayer = new Matrix(neuronMatrixCurrLayer->getNumRows(),weightMatrix->getNumCols(),0);
        utils::Math::MultiplyMatrix(neuronMatrixCurrLayer,weightMatrix,neuronMatrixNextLayer);
        for(int cIndx = 0;cIndx<neuronMatrixNextLayer->getNumCols();cIndx++)
            setNeuronValue(i+1,cIndx,neuronMatrixNextLayer->getValue(0,cIndx)+bais);
        delete(neuronMatrixCurrLayer);
        delete(neuronMatrixNextLayer);
    }
    stateValidator();
}