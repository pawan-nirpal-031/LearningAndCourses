#ifndef MATMUL_H 
#define MATMUL_H 

#include <iostream>
#include <vector>
#include <assert.h>
#include "../../include/Matrix.h"
using namespace std;

namespace utils{

Matrix* multiply(Matrix &M1, Matrix &M2){
    assert(M1.getNumCols()==M2.getNumRows() and "Invalid matrices for product");
    Matrix *NewMat = new Matrix(M1.getNumRows(),M2.getNumCols(),0);
    int a = M1.getNumRows();
    int b = M1.getNumCols();
    int c = M2.getNumCols();
    for(int i =0;i<a;i++){
        for(int j = 0;j<c;j++){
            for(int k =0;k<b;k++){
                double accum = M1.getValue(i,k)*M2.getValue(k,j);
                NewMat->setValue(i,j,NewMat->getValue(i,j)+accum);
            }
        }
    }
    return NewMat;
}
/*
    axb bxc
*/
}
#endif