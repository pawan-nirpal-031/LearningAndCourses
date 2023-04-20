#ifndef DATA_READER
#define DATA_READER

#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream> 
#include <assert.h>
using namespace std;

namespace utils{
    class DataReader{
    public:
        vector<vector<double>> fetchData(string &dataFilePath);
    };
}

#endif