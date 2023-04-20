#include "../../include/utils/DataManager.h"

vector<vector<double>> utils::DataReader::fetchData(string &dataFilePath){
    ifstream infile(dataFilePath);
    string line;
    vector<vector<double>>data;
    while(getline(infile,line)){
        vector<double> dataRow;
        string token;
        stringstream ss(line);
        while(getline(ss,token,','))
          dataRow.push_back(stod(token));
        data.push_back(dataRow);
    }
    return data;
}