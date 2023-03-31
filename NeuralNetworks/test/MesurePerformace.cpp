#include <iostream> 
using namespace std;


void MeausreClang(){
    int runs = 100000;
    for(int i =0;i<runs;i++){
        system("../OpenANN_Clang");
    }
}

void MeausreGcc(){
    int runs = 100000;
    for(int i =0;i<runs;i++){
        system("../OpenANN_GCC");
    }
}

void MeausreAocc(){
    int runs = 100000;
    for(int i =0;i<runs;i++){
        system("../OpenANN_Aocc");
    }
}

int main(){
    MeausreAocc();
}