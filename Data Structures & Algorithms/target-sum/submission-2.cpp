class Solution {
private:
    int ans=0,sum=0;
    void solve(vector<int> nums, int target, int idx){
        if(sum==target && idx==nums.size()) {ans++; return;}
        if(idx>=nums.size()) return;
        //plus
        sum+=nums[idx];
        solve(nums,target,idx+1);
        sum-=nums[idx];
        //minus
        sum-=nums[idx];
        solve(nums,target,idx+1);
        sum+=nums[idx];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ans=0;
        solve(nums,target,0);
        return ans;
    }
};
