class Solution {
private:
    void solve(int r, int c, int n, vector<string> board,
               vector<vector<string>>& ans) {
        if (r >= n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            board[r][i] = '*';
            board[i][c] = '*';
        }
        int dr = r, dc = c;
        while (dr < n && dc < n && dr >= 0 && dc >= 0) {
            board[dr++][dc++] = '*';
        }
        dr = r;
        dc = c;
        while (dr < n && dc < n && dr >= 0 && dc >= 0) {
            board[dr--][dc--] = '*';
        }
        dr = r;
        dc = c;
        while (dr < n && dc < n && dr >= 0 && dc >= 0) {
            board[dr--][dc++] = '*';
        }
        dr = r;
        dc = c;
        while (dr < n && dc < n && dr >= 0 && dc >= 0) {
            board[dr++][dc--] = '*';
        }
        if (r + 1 < n) {
            for (int i = 0; i < n; i++) {
                if (board[r + 1][i] != '*' && board[r + 1][i] != 'Q') {
                    auto newBoard = board;
                    newBoard[r][c] = 'Q';
                    solve(r + 1, i, n, newBoard, ans);
                }
            }
        } else {
            board[r][c] = 'Q';
            ans.push_back(board);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            vector<string> board(n, str);
            board[0][i] = 'Q';
            solve(0, i, n, board, ans);
        }
        for (auto& row : ans) {
            for (auto& line : row) {
                for (auto& ch : line) {
                    if (ch == '*')
                        ch = '.';
                }
            }
        }
        return ans;
    }
};
