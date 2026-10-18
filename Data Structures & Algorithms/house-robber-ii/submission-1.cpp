class Solution {
private:
    int solve(vector<int> &nums, vector<int> &dp, int idx, int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        dp[idx]=max(nums[idx]+solve(nums,dp,idx+2,n),solve(nums,dp,idx+1,n));
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int> dp1(n,-1);
        solve(nums,dp1,0,n-1);
        vector<int> dp2(n,-1);
        solve(nums,dp2,1,n);
        return max(dp1[0],dp2[1]);
    }
};

