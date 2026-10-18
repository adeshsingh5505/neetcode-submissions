class Solution {
vector<int> res;
int maxi=0;
private:
    void solve(vector<int> &nums, int idx){
        if(idx>=nums.size()){
            maxi=max(maxi,(int)res.size());
            return;
        }
        if(res.empty()||res.back()<nums[idx]){
            //take
            res.push_back(nums[idx]);
            solve(nums,idx+1);
            //not take
            res.pop_back();
            solve(nums,idx+1);
        }
        else{
            solve(nums,idx+1);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        maxi=-1e9;
        solve(nums,0);
        return maxi;
    }
};
