class Solution {
private:
    int solve(vector<int>& coins, int amount, int idx,vector<vector<int>> &dp){
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(idx==0){
            if(amount%coins[idx]==0) return dp[idx][amount]=(amount/coins[idx]);
            return 1e9;
        }
        //take
        int t=1e9;
        if(coins[idx]<=amount)
        t = 1 + solve(coins,amount-coins[idx],idx,dp);
        //not take
        int nt=solve(coins,amount,idx-1,dp);
        return dp[idx][amount]=min(nt,t);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int t=solve(coins,amount,n-1,dp);
        if(t==1e9) return -1;
        return t;
    }
};
