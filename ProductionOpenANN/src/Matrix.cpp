#include "../include/Matrix.h"

// delete the this object, it will gobble up too much memory when not in use
Matrix *Matrix::transpose(){
    Matrix *m = new Matrix(getNumCols(),getNumRows(),0);
    int r = getNumRows();
    int c = getNumCols();
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++) m->setValue(j,i,getValue(i,j));
    }
    return m;
}

Matrix *Matrix::copy(){
    int r = getNumRows();
    int c = getNumCols();
    Matrix *m = new Matrix(r,c,0);
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++) m->setValue(i,j,getValue(i,j));
    }
    return m;
}

double Matrix::generateRandomNumber(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution <> dis(-.0001,.0001);
    return dis(gen);
}

Matrix::Matrix(int r,int c,bool isRand){
    rows = r;
    cols = c;
    for(int i =0;i<r;i++){
        vector<double> row(c,0.0);
        if(isRand){
            for(int j =0;j<c;j++) row[j] = generateRandomNumber();
        }
        values.push_back(row);
    }
}

void Matrix::printToConsole(){
    for(int i =0;i<getNumRows();i++){
        for(int j =0;j<getNumCols();j++){
            cout<<getValue(i,j)<<"\n";
        }
        cout<<"\n";
    }
    cout<<'\n';
}