class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0,res=1e9;
        int s=0,e=0;
        for(int e=0;e<n;e++){
            sum+=nums[e];
            while(sum>=target){
                res=min(e-s+1,res);
                sum-=nums[s++];
            }
        }
        return res == 1e9 ? 0: res;
    }
};