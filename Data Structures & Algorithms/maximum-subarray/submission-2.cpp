class Solution {
int maxi=-1e9;
int sum=0;
    void solve(vector<int> nums, int idx){
        if(idx>=nums.size()){
            return;
        }
        sum+=nums[idx];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
        solve(nums,++idx);
    }
public:
    int maxSubArray(vector<int>& nums) {
        maxi=-1e9;
        solve(nums,0);
        return maxi;
    }
};
