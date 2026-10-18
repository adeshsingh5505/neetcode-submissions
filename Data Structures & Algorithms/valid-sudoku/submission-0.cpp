#include <vector>
#include <iostream>
using namespace std;

class Solution {
    bool checkR(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<int> v(9, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (v[idx]++) return false;
                }
            }
        }
        return true;
    }

    bool checkC(vector<vector<char>>& board) {
        for (int j = 0; j < 9; ++j) {
            vector<int> v(9, 0);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (v[idx]++) return false;
                }
            }
        }
        return true;
    }

    bool box(vector<vector<char>>& board, int i1, int i2, int j1, int j2) {
        vector<int> v(9, 0);
        for (int i = i1; i <= i2; ++i) {
            for (int j = j1; j <= j2; ++j) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (v[idx]++) return false;
                }
            }
        }
        return true;
    }

    bool checkS(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!box(board, i, i + 2, j, j + 2))
                    return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkC(board) && checkR(board) && checkS(board);
    }
};
