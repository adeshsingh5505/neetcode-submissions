class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> ms;
        int n=nums.size();
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        ans.push_back(*ms.rbegin());

        for(int i=1;i<=(n-k);i++){
        auto it = ms.find(nums[i-1]);  
        if (it != ms.end()) {
        ms.erase(it);  
        }
        ms.insert(nums[i+k-1]);
        ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};
