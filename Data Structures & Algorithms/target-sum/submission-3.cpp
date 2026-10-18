class Solution {
     int cnt=0;
private:
    void solve(vector<int> nums, int target, int idx, int sum){
        if(sum==target && idx==nums.size()) {cnt++; return;}
        if(idx>=nums.size()) return;
        //plus
        solve(nums,target,idx+1,sum+nums[idx]);
       
        //minus
        solve(nums,target,idx+1,sum-nums[idx]);
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        cnt=0;
        solve(nums,target,0,0);
        return cnt;
    }
};
