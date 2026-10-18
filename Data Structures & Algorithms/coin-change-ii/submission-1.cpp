class Solution {
int cnt=0;
private:
    int solve(vector<int> &coins, int amount, int idx,vector<vector<int>> &dp){
        if(amount==0){
            dp[idx][amount]=1;
        }
        if(amount<0 || idx>=coins.size()) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        //take self remain on self
        int l=solve(coins,amount-coins[idx],idx,dp);
        //do not take and go to next
        int m=solve(coins,amount,idx+1,dp);

        return dp[idx][amount]=l+m;
    }
public:
    int change(int amount, vector<int>& coins) {
        cnt=0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};
