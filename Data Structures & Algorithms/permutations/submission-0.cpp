class Solution {
vector<int> subset;
vector<bool>used;
    void solve(vector<int> nums,vector<vector<int>> &ans){
        if(subset.size()==nums.size()){
            ans.push_back(subset);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                subset.push_back(nums[i]);
                used[i]=1;
                solve(nums,ans);
                subset.pop_back();
                used[i]=0;
            }
        }
        

        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),0);
        vector<vector<int>> ans;
        solve(nums,ans);
        return ans;
    }
};
