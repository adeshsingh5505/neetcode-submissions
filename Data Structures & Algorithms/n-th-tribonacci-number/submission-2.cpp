class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        int tribN=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
        return dp[n]=tribN;
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0,dp[1]=1,dp[2]=1;
        return solve(n,dp);
    }
};