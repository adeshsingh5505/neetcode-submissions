class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int gmax=nums[0],gmin=nums[0],cmax=0,cmin=0;
        int total=0;
        for(auto &num: nums){
            cmax=max(num,cmax+num);
            cmin=min(num,cmin+num);
            gmax=max(gmax,cmax);
            gmin=min(gmin,cmin);
            total+=num;
        }
        if(gmax>0) return max(gmax,total-gmin);
        return gmax;
    }
};