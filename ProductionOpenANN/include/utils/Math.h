#ifndef MATH_H 
#define MATH_H 

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "../Matrix.h"
using namespace std;

bool MatrixValidate(Matrix *a,Matrix* b,Matrix *c,string point);

namespace utils{
    class Math{
    public:
        static void MultiplyMatrix(Matrix *a,Matrix *b,Matrix *c);
    };
}

#endif