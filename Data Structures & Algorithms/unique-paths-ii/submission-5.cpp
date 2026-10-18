class Solution {
vector<int> dx={1,0};
vector<int> dy={0,1};
private:
    int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp,
    int r, int c ,int n, int m){
        if(r>=n || c>=m || obstacleGrid[r][c]==1){
            return 0;
        }
        if(r==n-1 && c==m-1){
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int down=solve(obstacleGrid,dp,r+1,c,n,m);
        int right=solve(obstacleGrid,dp,r,c+1,n,m);
        return dp[r][c]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(obstacleGrid,dp,0,0,n,m);
    }
};