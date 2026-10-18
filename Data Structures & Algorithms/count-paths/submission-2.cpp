class Solution {
private:
    int solve(vector<vector<int>> &dp,int r, int c, int m, int n){
        if(r==m-1 && c==n-1) return 1;
        if(r>=m || c>=n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int down=solve(dp,r+1,c,m,n);
        int right=solve(dp,r,c+1,m,n);
        return dp[r][c]=down+right;
    }
public:
    int uniquePaths(int m, int n) {
        //solve using DP
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(dp,0,0,m,n);
    }
};
