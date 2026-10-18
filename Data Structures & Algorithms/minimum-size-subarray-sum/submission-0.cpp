class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    mini=min(mini,j-i+1);
                    break;
                }
            }
        }
        if(mini==1e9) return 0;
        return mini;
    }
};