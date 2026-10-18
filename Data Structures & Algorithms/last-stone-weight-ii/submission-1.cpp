class Solution {
private:
    int dfs(vector<int>& stones,int total, int stoneSum, int target, int idx,int n,vector<vector<int>> &dp){
        if(target>=stoneSum || idx>=n){
            return abs(target-(total-target));
        }
        if(dp[idx][target]) return dp[idx][target];
        return dp[idx][target]=min(dfs(stones,total,stoneSum,target,idx+1,n,dp),
        dfs(stones,total,stoneSum,target+stones[idx],idx+1,n,dp));
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(),stones.end(),0);
        int stoneSum = ceil(total/2);
        vector<vector<int>> dp(n,vector<int>(total,0));
        return dfs(stones,total,stoneSum,0,0,n,dp);
    }
};