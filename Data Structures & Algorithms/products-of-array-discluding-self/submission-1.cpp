class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count=0;
        int prod=1;
        for(auto &i:nums){
            if(i==0) zero_count++;
            else prod*=i;
        }
        int n=nums.size();
        vector<int> ans(n,0);
        if(zero_count>1) return ans;
        for(int i=0;i<n;i++){
            if(zero_count==0 && nums[i]!=0){
                ans[i]=prod/nums[i];
            }
            if(zero_count==1 && nums[i]==0){
                ans[i]=prod;
            }
        }
        return ans;
    }
};
