class Solution {
int total_xor=0;
private:
    void solve(vector<int> &nums, int idx, int cxor){
        if(idx>=nums.size()){
            total_xor+=cxor;
            return;
        }
        //take
        solve(nums,idx+1,cxor^nums[idx]);
        //not take
        solve(nums,idx+1,cxor);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        total_xor=0;
        for(int i=0;i<nums.size();i++){
            solve(nums,i+1,nums[i]);
        }
        return total_xor;
    }
};