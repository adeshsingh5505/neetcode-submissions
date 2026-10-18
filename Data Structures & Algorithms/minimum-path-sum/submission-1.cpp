class Solution {
int mini=1e9;
private:    
    int solve(vector<vector<int>>& grid, int r, int c, int n, int m,vector<vector<int>> &dp){
        if(r==n-1 && c==m-1){
            return grid[r][c];
        }
        if(r>=n || c>=m){
            return 1e9;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        //down
        int a=solve(grid,r+1,c,n,m,dp);
        //right
        
        int b=solve(grid,r,c+1,n,m,dp);

        return dp[r][c]=grid[r][c]+min(a,b);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        mini=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //solve(grid,0,0,n,m,grid[0][0],dp);
        for(auto i: dp){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
        return solve(grid,0,0,n,m,dp);
    }
};