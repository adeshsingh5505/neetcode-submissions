class Solution {
private:
    int maxi = -1;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};

    void djksh(vector<vector<int>>& grid, int row, int column, int n) {
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({grid[row][column], {row, column}});
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[row][column] = 1;

        while (!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int val = p.first;
            int r = p.second.first;
            int c = p.second.second;

            maxi = max(maxi, val);

            for (int i = 0; i < 4; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr == n - 1 && cc == n - 1) {
                        maxi = max(maxi, grid[rr][cc]);
                        return;
                    }
                if (rr >= 0 && rr < n && cc >= 0 && cc < n && !visited[rr][cc]) {

                    pq.push({grid[rr][cc], {rr, cc}});
                    visited[rr][cc] = 1;
                }
            }
        }
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        maxi = -1;
        int n = grid.size();
        djksh(grid, 0, 0, n);
        return maxi;
    }
};
