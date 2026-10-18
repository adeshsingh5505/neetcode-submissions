class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=0;
        int maxi=-1e9;
        while(i<nums.size()){
            int p=1;
            for(int j=i;j<nums.size();j++){
                p=p*nums[j];
                maxi=max(maxi,p);
            }
            i++;
        }
        return maxi;
    }
};
