class Solution {
int maxi=-1e9;
    int solve(vector<int> &prices, int b, int s,vector<vector<int>> &dp){
        if(s>=prices.size() || b>=prices.size() || s<b) return 0;
        if(dp[b][s]!=0) return dp[b][s];
        //deal done, proceed
        int d=(prices[s]-prices[b])+solve(prices,s+1,s+1,dp);
        //explore next
        int e=solve(prices,b,s+1,dp);
        //buy next
        int n=solve(prices,b+1,s,dp);
        return dp[b][s]=max({d,e,n});    
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        return solve(prices,0,0,dp);
    }
};