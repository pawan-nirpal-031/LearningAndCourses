#include <iostream> 
#include <vector> 
#include <map> 
#define Dbg 1 

class QLearning{
    const int StateSize; // In 2-dims , SS = 2
    const int ActionSize; 
    const int Range; 
    std::map<std::vector<int>,std::vector<float>>QTable; 
    bool Init;
    static double Discount; // How much to consider local reward over long term reward
    const static int Episodes = 10;
    static float EpDecayRate; 
    static double LearningRate;
public:
    // Construct a Q Table, Range is values the state can take. 
    QLearning(const int &States, const int &Actions, const int &Range);
    std::vector<int>IndexFromMulti(int oneDimIndx, int HalfRange, int Depth);
    void QTableLogic(int &HalfRage, int States, int Actions); 
    void Show() const;
    //probabilty of exploration 
    float GetEpsilon() const;
    void SetEpsilon(float);
};