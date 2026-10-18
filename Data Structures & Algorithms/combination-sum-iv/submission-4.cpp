class Solution {
private:
    int solve(vector<int> &nums, int target,int sum,vector<int> &dp){
        if(sum==target) return 1;
        if(sum>target) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ways = 0;
        for(auto i: nums){
            ways=ways+solve(nums,target,sum+i,dp);
        }
        return dp[sum] = ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target==0) return 1;
        int n= nums.size();
        vector<int> dp(target+1,-1);
        solve(nums,target,0,dp);
        for(auto i: dp) cout<<i<<" ";
        return dp[0];
    }
};