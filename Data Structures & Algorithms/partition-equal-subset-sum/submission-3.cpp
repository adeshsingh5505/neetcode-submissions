class Solution {
public:
//TC=O(target)
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return 0;
        int target=sum/2;
        vector<bool> dp(target,false);
        dp[0]=true;
        for(auto i:nums){
            for(int j=target;j>=i;j--){
                dp[j]=dp[j]||dp[j-i];
            }
        }
        return dp[target];
    }
};
