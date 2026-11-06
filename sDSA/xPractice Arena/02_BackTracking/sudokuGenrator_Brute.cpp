// Question : 
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int randomGen(int min, int max){
    std::random_device rd;
    int randomNum = rd();
    randomNum = randomNum % (max+1) + min;
    return (randomNum >= 0) ? (randomNum) : -randomNum ;
}

vector<vector<char>> generateRandomSudokuBoard(int grid) {
    int boardLen = grid*grid;
    int minVal = 0, maxVal = 9;
    vector<vector<char>> board (boardLen, vector<char>(boardLen, '.'));

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {

            int pick = randomGen(0, 9); // 0 = blank

            if (pick == 0) {
                board[i][j] = '.';
            } else {
                board[i][j] = '0' + pick; // '1' to '9'
            }
        }
    }
    return board;
}

void printArr(const vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int grid = 3; //3x3 = 9 col 9 row
    vector<vector<char>> board = generateRandomSudokuBoard(grid);
    printArr(board);
return 0;}
