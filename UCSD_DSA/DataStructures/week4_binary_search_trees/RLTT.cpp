#include <iostream> 
#include <vector>
using namespace std;

void SetBoardPositon(vector<vector<bool>> &board){
    board[0][0] = board[2][2] = board[1][1] = board[1][2] = 1; 
} 

bool CheckForWin(vector<vector<bool>> &board,bool &player){

}

int main(){
    vector<vector<bool>>board(3,vector<bool>(3,0)); 
    SetBoardPositon(board); 
    bool player = 1;
    CheckForWin(board,player);
    
}