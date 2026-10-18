class Solution {
private:
    int solve(vector<int>& prices,int b, int s, int n,vector<vector<int>> &dp){
        if(s>=n||b>=n || s<b) return 0;
        if(dp[b][s]!=-1) return dp[b][s];
        //deal done, proceed next
        int k=(prices[s]-prices[b])+solve(prices,s+2,s+3,n,dp);
        //deal not done, explore next
        int r=solve(prices,b,s+1,n,dp);
        //skip buying day
        int l=solve(prices,b+1,s,n,dp);
        return dp[b][s]=max({l,k,r});
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(prices,0,1,n,dp);
    }
};
