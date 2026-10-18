class Solution {
int s=0;
private:
    //O(2^n) solution
    bool solve(vector<int> &nums, int sum, int idx){
        if(idx>=nums.size()){
            return s==sum/2;
        }
        //take
        s+=nums[idx];
        if(solve(nums,sum,idx+1)) return 1;
        s-=nums[idx];
        //not take
        if(solve(nums,sum,idx+1)) return 1;
        return 0;
    }
public:
    bool canPartition(vector<int>& nums) {
        s=0;
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0) return 0;
        return solve(nums,sum,0);
    }
};
