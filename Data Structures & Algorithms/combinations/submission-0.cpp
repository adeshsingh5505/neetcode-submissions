class Solution {
vector<int> combination;
private:
    void solve(int n, int k, vector<vector<int>> &ans,int idx){
        if(combination.size()==k){
            ans.push_back(combination);
            return;
        }
        if(idx>n) return;
        //take
        combination.push_back(idx);
        solve(n,k,ans,idx+1);
        combination.pop_back();
        //not take
        solve(n,k,ans,idx+1);    
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        solve(n,k,ans,1);
        return ans;
    }
};