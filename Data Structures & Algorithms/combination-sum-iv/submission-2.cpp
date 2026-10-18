class Solution {
private:
    int solve(vector<int> &nums, int target,vector<int> &dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ways = 0;
        for(auto i: nums){
            ways=ways+solve(nums,target-i,dp);
        }
        return dp[target] = ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(auto i: nums) sum+=i;
        vector<int> dp(target+1,-1);
        dp[0]=1;
        for(auto i: nums){
            solve(nums,target,dp);
        }
        for(auto i: dp) cout<<i<<" ";
        return dp[target];
    }
};