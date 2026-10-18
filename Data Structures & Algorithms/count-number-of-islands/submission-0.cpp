class Solution {
private:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int n, int l, int i, int j) {
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({i, j});
        //4 possible direction
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < l &&
                    grid[nr][nc] == '1' && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int l = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(l, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(grid, visited, n, l, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
