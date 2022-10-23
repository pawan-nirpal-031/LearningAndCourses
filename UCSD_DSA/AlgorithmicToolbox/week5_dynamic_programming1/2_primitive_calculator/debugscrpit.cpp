#include <iostream> 
#include <fstream> 
using namespace std; 

int main(){
    ofstream fout("debug.sh");
    fout<<"g++ primitive_calculator.cpp && ./a.out"<<'\n';
    fout<<"gdb ./a.out"<<'\n';
    string break_points; 
    int x[] = {
        52,
        19,
        25,
        26,
        27,
        29,
        31,
        33,
        37,
        39
    };
    for(const int &bk : x){
        break_points+=("b "+to_string(bk)+'\n');
    }
    fout<<break_points;
    fout<<"run\n";
    fout<<"105000\n";
    for(int i =0;i<100;i++){
        fout<<"c\nbt\n";
    }
   // system("bash debug.sh");
    return 0;
}