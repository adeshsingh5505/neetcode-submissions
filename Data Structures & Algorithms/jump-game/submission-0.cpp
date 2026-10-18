class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return 1;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            if(maxi<i) return 0;
            maxi=max(nums[i]+i,maxi);
        }
        return 1;
    }
};
