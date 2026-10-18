class Solution {
vector<int> subset;
   void solve(vector<int> nums,vector<vector<int>> &ans, int idx){
    if(idx>=nums.size()){
        ans.push_back(subset);
        return;
    }
    //not take
    //subset.push_back(nums[idx]);
    solve(nums,ans,idx+1);
    //not take
    //subset.pop_back();
    subset.push_back(nums[idx]);
    solve(nums,ans,idx+1);
    subset.pop_back();
   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        subset={};
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};
