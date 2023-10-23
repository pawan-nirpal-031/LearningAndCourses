#include <iostream> 
using namespace std;


int main(){
    unsigned int x = 150000000;
    long unsigned int y = 48;
    cout<<sizeof(y)*8<<" "<<(x*y);
    return 0;
}