class Solution {
private:
    int solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=max(nums[idx]+solve(nums,idx+2,dp),solve(nums,idx+1,dp));
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums[0];
        vector<int> dp(n,-1);
        solve(nums,0,dp);
        return dp[0];
    }
};
