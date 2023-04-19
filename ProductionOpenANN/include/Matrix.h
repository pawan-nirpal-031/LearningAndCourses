#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <assert.h>

using namespace std;

class Matrix{
public:
    Matrix(int row,int cols,bool isRandom);
    Matrix* transpose();
    Matrix* copy();
    void setValue(int r,int c,double val){ values[r][c] = val; }
    double getValue(int r,int c){ return values[r][c]; }
    int getNumRows(){ return rows;}
    int getNumCols(){ return cols;}
    void printToConsole();
private:
    int rows,cols;
    vector<vector<double>> values;
    double generateRandomNumber();
};

#endif