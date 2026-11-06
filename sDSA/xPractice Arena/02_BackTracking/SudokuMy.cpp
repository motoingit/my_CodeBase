// Question : 
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int number){

    //column
    for(int i = 0; i < board.size(); i++) {
        if(board[i][col] == (char)('0' + number)) {
            return false;
        }

        if(board[row][i] == (char)('0' + number)) {
            return false;
        }

    }

    //grid
    int strRow = 3 * (row/3); //! This assumes a 9×9 Sudoku.
    int strCol = 3 * (col/3);
    
    for(int i=strRow; i<strRow+3; i++) {
        for(int j=strCol; j<strCol+3; j++) {
            if(board[i][j] == (char)('0' + number)) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuHelper(vector<vector<char>> &board, int currRow, int currCol){
    if(currRow == board.size()){
        return true; // It returns true only when fully solved.
    }

    //increment-condition + Next idx Calcu
    int nextRow=0, nextCol=0;
    if(currCol == board.size() - 1){ //todo: agar cone mai pahucha
        nextCol = 0;
        nextRow = currRow + 1;
    }else{
        nextCol = currCol + 1;
        nextRow = currRow;
    }

    if(board[currRow][currCol] != '.'){ //skip if any no alrady
        if(sudokuHelper(board, nextRow, nextCol)){
            return true;
        }
    }else{
        //filing the place
        for(int i = 1; i <= board.size(); i++) { // filling 1 to 9
            if(isSafe(board, currRow, currCol, i)){
                board[currRow][currCol] = (char)('0'+ i);
                if(sudokuHelper(board, nextRow, nextCol)){
                    return true;
                }else{
                    board[currRow][currCol] = '.';
                }
            }
        }
    }

    return false;
}

void solveSudoku( vector<vector<char>> &board){
    if(sudokuHelper(board, 0, 0)){ //start scanning from first bolck
        cout << "Soved " << endl;
    }else{
        cout << "Not Soved " << endl;
    }
}

void printArr(const vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    // int grid = 3; //3x3 = 9 col 9 row
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };


    solveSudoku(board);
    printArr(board);

return 0;}
