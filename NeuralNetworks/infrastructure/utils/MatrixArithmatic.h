#ifndef MATMUL_H 
#define MATMUL_H 

#include <iostream>
#include <vector>
#include <assert.h>
#include "../../include/Matrix.h"
using namespace std;

namespace utils{

Matrix* multiply(Matrix *M1, Matrix *M2){
    assert(M1->getNumCols()==M2->getNumRows() and "Invalid matrices for product");
    Matrix *NewMat = new Matrix(M1->getNumRows(),M2->getNumCols(),0);
    int a = M1->getNumRows();
    int b = M1->getNumCols();
    int c = M2->getNumCols();
    for(int i =0;i<a;i++){
        for(int j = 0;j<c;j++){
            for(int k =0;k<b;k++){
                double accum = M1->getValue(i,k)*M2->getValue(k,j);
                NewMat->setValue(i,j,NewMat->getValue(i,j)+accum);
            }
        }
    }
    return NewMat;
}
/*
    axb bxc
*/

Matrix* subtract(Matrix &M1, Matrix &M2){
    assert((M1.getNumRows()==M2.getNumRows() and M1.getNumCols()==M2.getNumCols()) and "Invalid matrices for subtraction");
    Matrix *newMat = new Matrix(M1.getNumRows(),M2.getNumCols(),0);
    int r = M1.getNumRows();
    int c = M1.getNumCols();
    for(int i =0;i<r;i++){
        for(int j = 0;j<c;j++){
            newMat->setValue(i,j,M1.getValue(i,j)-M2.getValue(i,j));
        }
    }
    return newMat;
}
/*
    axb axb
*/

Matrix* addition(Matrix &M1, Matrix &M2){
    assert((M1.getNumRows()==M2.getNumRows() and M1.getNumCols()==M2.getNumCols()) and "Invalid matrices for subtraction");
    Matrix *newMat = new Matrix(M1.getNumRows(),M2.getNumCols(),0);
    int r = M1.getNumRows();
    int c = M1.getNumCols();
    for(int i =0;i<r;i++){
        for(int j = 0;j<c;j++){
            newMat->setValue(i,j,M1.getValue(i,j)+M2.getValue(i,j));
        }
    }
    return newMat;
}
/*
    axb axb
*/

vector<double> matrixToVector(const Matrix &Mat){
    vector<double> matToVec;
    int rows = Mat.getNumRows();
    int cols = Mat.getNumCols();
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            matToVec.push_back(Mat.getValue(i,j));
        }
    }
    return matToVec;
}

}
#endif