#include "../../include/utils/Math.h"

void utils::Math::MultiplyMatrix(Matrix *a,Matrix *b,Matrix *c){
    int ar = a->getNumRows();
    int ac = a->getNumCols();
    int br = b->getNumRows();
    int bc = b->getNumCols();
    int cr = c->getNumRows();
    int cc = c->getNumCols();
    assert((ac==br and (ar==cr and bc==cc)) and "Matrices incompatible dimensions");
    for(int i =0;i<ar;i++){
        for(int j = 0;j<bc;j++){
            for(int k = 0;k<ac;k++){
                double v = a->getValue(i,k)*b->getValue(k,j);
                c->setValue(i,j,c->getValue(i,j)+v);
            }
        }
    }
}

bool MatrixValidate(Matrix *a,Matrix* b,Matrix *c,string point){
    int ar = a->getNumRows();
    int ac = a->getNumCols();
    int br = b->getNumRows();
    int bc = b->getNumCols();
    int cr = c->getNumRows();
    int cc = c->getNumCols();
    if((ac==br and (ar==cr and bc==cc))){
        cout<<"matrices ready at point : "<<point<<"\n";
        return 1;
    }
    cout<<"matrices faulty at point : "<<point<<"\n"; 
    cout<<"A rows : "<<ar<<" A cols : "<<ac<<" B rows : "<<br<<"B cols : "<<bc<<" C rows : "<<cr<<" C cols : "<<cc<<"\n";
    return 0;
}