class Solution {
int maxi=1;
vector<int> dr={-1,1,0,0};
vector<int> dc={0,0,1,-1};
private:
    void dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, int cnt){
        for(int k=0;k<4;k++){
            maxi=max(maxi,cnt);
            int rr=i+dr[k];
            int cc=j+dc[k];
            if(rr<n && cc<m && rr>=0 && cc>=0 && matrix[rr][cc]>matrix[i][j]){
                dfs(matrix,rr,cc,n,m,cnt+1);
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxi = 1;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(matrix, i, j, n, m, 1);
            }
        }
        return maxi;
    }
};
