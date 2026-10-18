class Solution {
    int cnt = 0;
    int dx[4] = { 1, 0}; 
    int dy[4] = { 0, 1}; 

private:
    void dfs(int r, int c, int m, int n, vector<vector<bool>> &visited) {
        if (r == m - 1 && c == n - 1) {
            cnt++;
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int rr = r + dx[i];
            int cc = c + dy[i];

            if (rr >= 0 && rr < m && cc >= 0 && cc < n && !visited[rr][cc]) {
                dfs(rr, cc, m, n, visited);
            }
        }

        visited[r][c] = false;
    }

public:
    int uniquePaths(int m, int n) {
        cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(0, 0, m, n, visited);
        return cnt;
    }
};
