// Question : 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(const vector<vector<char>>& board, int i, int j, char v) {
        for(int k = 0; k < 9; k++) {
            if(board[i][k] == v) return false;
            if(board[k][j] == v) return false;
            if(board[i/3*3+k/3][j/3*3+k%3] == v) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') continue;
                for(char v = '1'; v <= '9'; v++) {
                    if(check(board, i, j, v)){
                        board[i][j] = v;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
