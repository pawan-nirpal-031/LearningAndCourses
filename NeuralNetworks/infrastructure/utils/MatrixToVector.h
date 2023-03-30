#ifndef MAT_TO_VEC
#define MAT_TO_VEC


#include <iostream>
#include <vector>
#include <assert.h>
#include "../../include/Matrix.h"
using namespace std;

namespace utils{
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