class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j=0;
        vector<int> v;
        while(j<nums.size()){
            for(int i=j+1;i<nums.size();i++){
                if(nums[j]+nums[i]==target){
                    v.push_back(j);
                    v.push_back(i);
                }
            }
            j++;
        }
        return v;
    }
};
