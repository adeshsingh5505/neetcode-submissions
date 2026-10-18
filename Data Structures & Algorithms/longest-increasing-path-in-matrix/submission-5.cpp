class Solution {
vector<int> dr={-1,1,0,0};
vector<int> dc={0,0,1,-1};
private:
    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int maxP=1;
        for(int k=0;k<4;k++){
            int rr=i+dr[k];
            int cc=j+dc[k];
            if(rr<n && cc<m && rr>=0 && cc>=0 && matrix[rr][cc]>matrix[i][j]){
                maxP=max(maxP,1+dfs(matrix,rr,cc,n,m,dp));
            }
        }
        return dp[i][j]=maxP;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = 1;
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi=max(maxi,dfs(matrix, i, j, n, m,dp));
            }
        }
        return maxi;
    }
};
