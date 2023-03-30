#include "../include/Matrix.h"
#include <random>
#include <iostream>
#include <assert.h>
using namespace std;

Matrix::Matrix(int rows,int cols,bool isRand){
    this->rows = rows;
    this->cols = cols;
    for(int i =0;i<rows;i++){
        vector<double>row;
        for(int j = 0;j<cols;j++){
            double v = 0.00;
            if(isRand) v = this->generateRandomNumber();
            row.push_back(v);
        }
        this->Values.push_back(row);
    }
}

void Matrix::printToConsole(){
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cout<<Values[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Matrix::setValue(int row,int col,double Value){
    assert(row<this->rows and col<this->cols and "setting invalid entry in matrix");
    Values[row][col] = Value;
}

double Matrix::getValue(int row,int col){
    assert(row<this->rows and col<this->cols and "accessing invalid entry in matrix");
    return Values[row][col];
}

double Matrix::generateRandomNumber(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<>dis(0,1);
    return dis(gen); 
}

Matrix* Matrix::transpose(){
    Matrix *newMat = new Matrix(this->cols,this->rows,0);
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            newMat->setValue(j,i,getValue(i,j));
        }
    }
    return newMat;
}
