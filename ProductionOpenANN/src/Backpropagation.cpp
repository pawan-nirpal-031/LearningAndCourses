#include "../include/NeuralNetwork.h"
#include "../include/utils/Math.h"



void NeuralNetwork::backpropagation(){
    /*
        part 1 : output to last hidden layer 
        part 2 : last hidden layer to input layer
    */
    vector<Matrix*> newWeights;
    int ouputLayrIndx = topologySize-1;

    // set gradients at the ouput layer 
    Matrix *deltaWeights = new Matrix(weightMatrices[ouputLayrIndx-1]->getNumRows(),weightMatrices[ouputLayrIndx-1]->getNumCols(),0);
    Matrix *gradients = new Matrix(1,topology[ouputLayrIndx],0);
    Matrix* derivedVals = Layers[ouputLayrIndx]->matrixifyDerivedValues();
    for(int i=0;i<topology[ouputLayrIndx];i++){
        double g = derivedErrors[i]*derivedVals->getValue(0,i);
        gradients->setValue(0,i,g);
    }
    delete(derivedVals); // was used in setting gradients so no use of this last layer derived vals
    Matrix *zActivatedValues = Layers[ouputLayrIndx-1]->matrixifyActivatedValues()->transpose();
    // compute delta weights DW = Gt * Z // should it not be DWt 
    utils::Math::MultiplyMatrix(zActivatedValues,gradients,deltaWeights);
    delete(zActivatedValues); // remove the previous matrix
    // compute New weights last hidden to output
    Matrix *tempNewWeights = new Matrix(topology[ouputLayrIndx-1],topology[ouputLayrIndx],0);
    
    for(int r = 0;r<topology[ouputLayrIndx-1];r++){
        for(int c = 0;c<topology[ouputLayrIndx];c++){
            double orignalWt = weightMatrices[ouputLayrIndx-1]->getValue(r,c);
            double deltaVal = deltaWeights->getValue(r,c);
            orignalWt *= momentum;
            deltaVal *= learningRate;
            tempNewWeights->setValue(r,c,(orignalWt-deltaVal));
        }
    }
    newWeights.push_back(new Matrix(*tempNewWeights));
    delete(tempNewWeights);
    delete(deltaWeights);

    // Part 2, last hidden to input
    for(int i = ouputLayrIndx-1;i>0;i--){
        Matrix *pGradients = gradients; // gradients to right of current layer (when starting the loop it will be for output layer) 
        gradients = new Matrix(1,topology[i],0);
        if(i==1){// here value of ZactivatedVals will be equal to input values, else they'll be zActivatedValues,
            zActivatedValues = Layers[0]->matrixifyValues();
        }else{
            zActivatedValues = Layers[i-1]->matrixifyActivatedValues();
        }
    
        // perform G = (Gp * WpT) * Z'
        // as such G = Gp * WpT, then G = G * Z' 
        Matrix *prevWeightsTransoposed = weightMatrices[i]->transpose(); //delete later 
        utils::Math::MultiplyMatrix(pGradients,prevWeightsTransoposed,gradients);
        Matrix *hiddenDerived = Layers[i]->matrixifyActivatedValues();
        for(int cnt =0;cnt<hiddenDerived->getNumRows();cnt++){
            double g = gradients->getValue(0,cnt)*hiddenDerived->getValue(0,cnt);
            gradients->setValue(0,cnt,g);
        }
        // compute delta weights for hidden to hidden 
        // Dw = xT * Gh
        Matrix* transposedHidden = zActivatedValues->transpose(); // this is xT
        deltaWeights = new Matrix(topology[i-1],topology[i],0);
        utils::Math::MultiplyMatrix(transposedHidden,gradients,deltaWeights);

        // Now update weights compute new weights 
        Matrix *tempNewWeights = new Matrix(topology[i-1],topology[i],0);
    
        for(int r = 0;r<topology[i-1];r++){
            for(int c = 0;c<topology[i];c++){
                double orignalWt = weightMatrices[i-1]->getValue(r,c);
                double deltaVal = deltaWeights->getValue(r,c);
                orignalWt *= momentum;
                deltaVal *= learningRate;
                tempNewWeights->setValue(r,c,(orignalWt-deltaVal));
            }
        }
        newWeights.push_back(new Matrix(*tempNewWeights));
        // Loop Cleanup 
        delete(tempNewWeights);
        delete(deltaWeights);
        delete(zActivatedValues);
        delete(transposedHidden);
        delete(hiddenDerived);
        delete(prevWeightsTransoposed);
        delete(pGradients); 
    }
    // Cleanup
    for(int i =0;i<weightMatrices.size();i++)
      delete(weightMatrices[i]);
    reverse(newWeights.begin(),newWeights.end());
    for(int i =0;i<newWeights.size();i++)
        weightMatrices[i] = (newWeights[i]);
    newWeights.clear();
    delete(gradients);
    stateValidator();
}