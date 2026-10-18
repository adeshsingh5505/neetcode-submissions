class Solution {
vector<int> subset;
int sum=0;
    void solve(vector<int> nums,vector<vector<int>> &ans,int idx, int target){
        if(idx>=nums.size()){
            if(sum==target)
            ans.push_back(subset);
            return;
        }
        if(sum>target)
            return;
        //take
        sum+=nums[idx];
        subset.push_back(nums[idx]);
        solve(nums,ans,idx,target);
        //not take
        sum-=nums[idx];
        subset.pop_back();
        solve(nums,ans,idx+1,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        subset={};
        vector<vector<int>> ans;
        solve(nums,ans,0,target);
        return ans;
    }
};
