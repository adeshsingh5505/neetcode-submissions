class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=(n-k);i++){
            int maxi=-1;
            for(int l=i;l<=(i+k-1);l++){
                maxi=max(maxi,nums[l]);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};
