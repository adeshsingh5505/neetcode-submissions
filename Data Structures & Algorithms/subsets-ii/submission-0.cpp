class Solution {
vector<int> subset;
vector<bool> used;
private:
    void solve(vector<int> nums,vector<vector<int>> &ans, int idx){
        ans.push_back(subset);
        if(subset.size()>=ans.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            solve(nums,ans,i+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //used.resize(nums.size())
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,ans,0);
        return ans;
    }
};
