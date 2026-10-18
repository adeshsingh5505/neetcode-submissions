class Solution {
vector<int> subset;
private:
    void solve(vector<int>& nums,set<vector<int>> &st,vector<int> &visited){
        if(subset.size()==nums.size()){
            st.insert(subset);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=1;
                subset.push_back(nums[i]);
                solve(nums,st,visited);
                subset.pop_back();
                visited[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> visited(nums.size(),0);
        solve(nums,st,visited);
        vector<vector<int>> ans;
        for(auto i: st){
            ans.push_back(i);
        }
        return ans;
    }
};