class Solution {
int sum=0;
private:
    void solve(vector<int> &nums, int idx, int local){
        if(idx>=nums.size()){
            sum+=local;
            return;
        }
        //take
        solve(nums,idx+1,local^nums[idx]);
        
        //not take
        solve(nums,idx+1,local);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        sum=0;
        solve(nums,0,0);
        return sum;
    }
};