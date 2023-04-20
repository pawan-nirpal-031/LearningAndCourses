#include "../include/NeuralNetwork.h"
#define debug 1

NeuralNetwork::NeuralNetwork(vector<int> &topology,double bais,double learningRate,double momentum){
    this->topology = topology;
    this->bais = bais;
    this->learningRate = learningRate;
    this->momentum = momentum;
    this->topologySize = topology.size();
    errors.resize(topology[topologySize-1]);
    derivedErrors.resize(topology[topologySize-1]);

    // populate layers
    for(int i =0;i<topologySize;i++){
        if(i==0){
            Layer *l = new Layer(topology[0]);
            Layers.push_back(l);
        }else if(i<topologySize-1){// hidden layers
            Layer *l = new Layer(topology[i],hiddenActivationType);
            Layers.push_back(l);
        }else{
            Layer *l = new Layer(topology[i],outputActivationType);
            Layers.push_back(l);
        }
    }

    // create weight matrices
    for(int i =0;i<topologySize-1;i++){
        Matrix *wghtMatrix = new Matrix(topology[i],topology[i+1],true);
        weightMatrices.push_back(wghtMatrix);
    }
    // set errors for last layer
    for(int i =0;i<topology[topologySize-1];i++){
        errors.push_back(0.00);
        derivedErrors.push_back(0.00);
    }
    error = 0.00;
}

NeuralNetwork::NeuralNetwork(vector<int> &topology,int hiddenActivation,int ouputActivation,int costFunctionType,double bais,double learningRate, double momentum){
    this->topology = topology;
    this->bais = bais;
    this->learningRate = learningRate;
    this->momentum = momentum;
    this->topologySize = topology.size();
    this->hiddenActivationType = hiddenActivation;
    this->outputActivationType = outputActivationType;
    this->costFunctionType = costFunctionType;

    // populate Layers
    for(int i =0;i<topologySize;i++){
        if(i==0){
            Layer *l = new Layer(topology[0]);
            Layers.push_back(l);
        }else if(i<topologySize-1){// hidden layers
            Layer *l = new Layer(topology[i],hiddenActivationType);
            Layers.push_back(l);
        }else{
            Layer *l = new Layer(topology[i],outputActivationType);
            Layers.push_back(l);
        }
    }

    // create weight matrices
    for(int i =0;i<topologySize-1;i++){
        Matrix *wghtMatrix = new Matrix(topology[i],topology[i+1],true);
        weightMatrices.push_back(wghtMatrix);
    }
    
    // set errors for last layer
    for(int i =0;i<topology[topologySize-1];i++){
        errors.push_back(0.00);
        derivedErrors.push_back(0.00);
    }
    error = 0.00;
}

void NeuralNetwork::stateValidator(){
    assert(topologySize==topology.size() and "topology fault!");
    assert(input.size()>0 and "input not set!");
    assert(target.size()>0 and "target not set!");
    assert(topology[topologySize-1]==Layers[topologySize-1]->getNumNeurons() and "Output layers size fault!");
    assert(Layers.size()==topology.size() and "Network topology and layer fault");
    assert(weightMatrices.size()==topologySize-1 and "incorrect number of weight matrices"); 
    for(int i =0;i<weightMatrices.size();i++){
        assert((topology[i]==weightMatrices[i]->getNumRows() and topology[i+1]==weightMatrices[i]->getNumCols()) and "weight matrices dimensions sreewd");
    }
}

void NeuralNetwork::printTotalError(){
    cout<<fixed<<setprecision(5)<<error<<"\n";
}

void NeuralNetwork::printOutputLayer(){
    Layer &output = *Layers[topologySize-1];
    for(int i =0;i<output.getNumNeurons();i++){
        cout<<output.getActivatedValue(i)<<" ";
    }
    cout<<'\n';
}

void NeuralNetwork::printNetworkArchitecture(){
    cout<<"topology : \n";
    for(int i =0;i<topology.size();i++){
        assert(Layers[i]->getNumNeurons()==topology[i] and "layer size and topology does not match!");
        cout<<" layer : "<<i<<" layer size : "<<topology[i]<<"\n";
    }
    cout<<"\n";
    cout<<"input : \n";
    for(auto &d : input){
        cout<<d<<" ";
    }
    cout<<"\n";
    cout<<"taregt : \n";
    for(auto &d : target){
        cout<<d<<" ";
    }
    cout<<"\n";
    cout<<"weight matrices : \n";
    for(int i =0;i<weightMatrices.size();i++){
        weightMatrices[i]->printToConsole();
    }
}

void NeuralNetwork::trainEpochs(vector<double> &input,vector<double>&target,double bais,double learningRate,double momentum,int epochs){
    this->learningRate = learningRate;
    this->bais = bais;
    this->momentum = momentum;
    setCurrentInput(input);
    setCurrentTarget(target);
    for(int e =0; e< epochs;e++){
        printTotalError();
        feedforward();
        setErrors();
        backpropagation();
    }
}

void NeuralNetwork::train(vector<double> &input,vector<double>&target,double bais,double learningRate,double momentum){
    this->learningRate = learningRate;
    this->bais = bais;
    this->momentum = momentum;
    #if debug
        cout<<"setting inputs\n"; 
    #endif
    setCurrentInput(input);
    #if debug
        cout<<"setting target\n"; 
    #endif
    setCurrentTarget(target);
    #if debug
        cout<<"printing error\n"; 
    #endif
    printTotalError();
    #if debug
        cout<<"running feedforward\n"; 
    #endif
    feedforward();
    #if debug
        cout<<"running set errors\n"; 
    #endif
    setErrors();
    #if debug
        cout<<"running backprop\n"; 
    #endif
    backpropagation();
}