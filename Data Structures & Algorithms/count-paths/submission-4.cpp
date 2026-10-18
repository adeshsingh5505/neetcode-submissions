class Solution {
//TC=O(m*n)
public:
    int uniquePaths(int m, int n) {
        //every block has 1 way to reach destination
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //if previous blocks have a and b ways then next block will be a+b ways
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
