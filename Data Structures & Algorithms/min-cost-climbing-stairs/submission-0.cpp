class Solution {
private:
    int dfs(vector<int> &cost, vector<int> &dp, int idx){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=cost[idx]+min(dfs(cost,dp,idx+1),dfs(cost,dp,idx+2));
        return dp[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        for(int i:dp)cout<<i<<" ";
        cout<<endl;
        return min(dfs(cost,dp,0),dfs(cost,dp,1));
    }
};
