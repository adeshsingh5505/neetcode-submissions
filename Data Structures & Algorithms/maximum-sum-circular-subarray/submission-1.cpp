class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMin=nums[0],globalMax=nums[0],currMax=0,currMin=0;
        for(int i=0;i<nums.size();i++){
            currMax=max(currMax+nums[i],nums[i]);
            currMin=min(currMin+nums[i],nums[i]);
            globalMin=min(globalMin,currMin);
            globalMax=max(globalMax,currMax);
        }
        if(globalMax>0)return max(globalMax,(accumulate(nums.begin(),nums.end(),0)-globalMin));
        else return globalMax;
    }
};