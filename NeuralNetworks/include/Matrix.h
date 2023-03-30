#ifndef MATRIX_H 
#define MATRIX_H 
#include <vector>
using namespace std; 

class Matrix{
private: 
    int rows; 
    int cols;
    vector<vector<double>>Values;
public: 
    Matrix(int rows,int cols,bool isRandom);
    Matrix* transpose(); 
    void setValue(int row,int col,double Value);
    double getValue(int row,int col);
    double generateRandomNumber();
    int getNumRows(){ return rows;}
    int getNumCols(){ return cols;}
    void printToConsole();
};

#endif