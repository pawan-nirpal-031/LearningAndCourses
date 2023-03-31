#include "../include/NeuralNetwork.h"
#include "../infrastructure/utils/MatrixArithmatic.h"
#include <assert.h>
using namespace std;

NeuralNetwork::NeuralNetwork(vector<int> &Topology){
    this->Topology = Topology;
    Error = 0.0;
    TopologySize = Topology.size();
    for(int i =0;i<TopologySize;i++){
        Layer *L = new Layer(Topology[i]);
        this->Layers.push_back(L);
    }
    for(int i =0;i<TopologySize-1;i++){
        Matrix *m = new Matrix(Topology[i],Topology[i+1],1);
        WeightMatrices.push_back(m);
    }
    Errors.resize(Topology.back());
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
        cout<<"\n\nLayer "<<i<<endl;
        Matrix m = ((i==0)?Layers[0]->matrixifyValues():Layers[i]->matrixifyActivatedValues());
        m.printToConsole();
        cout<<"===================\n";
        if(i<Layers.size()-1){
            cout<<"Weight matrix at : "<<i<<endl;
            WeightMatrices[i]->printToConsole();
        }
        cout<<"===================\n";
    }
}

// Will grow more sophisticated as we go
double NeuralNetwork::costFunction(double CurrVal,double Target){ 
    return CurrVal-Target;
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

void NeuralNetwork::setCurrentTarget(vector<double> &Target){
    this->Target = Target;
}

void NeuralNetwork::printErrors(){
    for(int i =0;i<Errors.size();i++){
        cout<<i<<" error : "<<Errors[i]<<endl;
    }
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

void NeuralNetwork::setErrors(){
    assert(Target.size()>0 and "No target for this network assign or set a target.");
    assert(Target.size()==Layers[Layers.size()-1]->getNumberOfNeurons() and "Target size not the same as output layer");
    Error = 0.0;
    int outputLayerIndx = Layers.size()-1;
    vector<Neuron*> &outputNeurons = Layers[outputLayerIndx]->getNeuronList();
    for(int i =0;i<Target.size();i++){
        assert(outputNeurons[i]!=nullptr and "Empty neuron in output layer");
        Errors[i] = costFunction(outputNeurons[i]->getActivatedValue(),Target[i]);
        Error+=Errors[i];
    }
    HistoricalErrors.push_back(Error);
}

void NeuralNetwork::backpropagation(){
    vector<Matrix*> updatedWeights;
    int outputLayerIndx = Layers.size()-1;
    Matrix derivedValuesHiddToOutput = Layers[outputLayerIndx]->matrixifyDerivedValues();
    Matrix *gradientHiddToOutput = new Matrix(1,Layers[outputLayerIndx]->getNumberOfNeurons(),0);
    // Gradient computation for last layer
    for(int i =0;i<Errors.size();i++){
        double derivedValCurrNeuron = derivedValuesHiddToOutput.getValue(0,i);
        double gradient = derivedValCurrNeuron*Errors[i];
        gradientHiddToOutput->setValue(0,i,gradient);
    } 
    int lastHiddnLayerIndx = outputLayerIndx -1;
    Layer *lastHiddenLayer = Layers[lastHiddnLayerIndx];
    Matrix lastHiddenLayerActivated = Layers[lastHiddnLayerIndx]->matrixifyActivatedValues();
    Matrix *DeltaWeights = utils::multiply(*gradientHiddToOutput->transpose(),lastHiddenLayerActivated)->transpose();
    Matrix *updatedWeightsHiddnToOutput = utils::subtract(*WeightMatrices[lastHiddnLayerIndx],*DeltaWeights);
    updatedWeights.push_back(updatedWeightsHiddnToOutput);
    cout<<"\n\norignal weights matrix : \n";
    WeightMatrices[lastHiddnLayerIndx]->printToConsole();
    cout<<"\n\nupdated weights matrix : \n";
    updatedWeightsHiddnToOutput->printToConsole();
    // moving back from last hidden layer to previous ones
    for(int i = lastHiddnLayerIndx;i>0;i--){
        Layer *CurrLayer = Layers[i];
        auto DerivedValsMatrix = CurrLayer->matrixifyDerivedValues();
        

    }
}
