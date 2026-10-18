class Solution {
vector<int> subset;
int sum=0;
    void solve(vector<int> nums,int target, int idx, vector<vector<int>> &ans){
        if(sum==target){
        ans.push_back(subset);
        return;
        }
        if(sum>target) return;
     
        for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]) continue;
         //take
        sum+=nums[i];
        subset.push_back(nums[i]);
        solve(nums,target,i+1,ans);
        //not take
        sum-=nums[i];
        subset.pop_back();
        }
        
       

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        solve(candidates,target,0,ans);
        return ans;
    }
};
