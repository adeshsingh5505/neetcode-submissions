class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v(2000,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]+1000]++;
        }
        vector<vector<int>> vv(nums.size()+1);
        
        for(int i=0;i<2000;i++){
            if(v[i]>0){
                vv[v[i]].push_back(i-1000);
            }
        }
       vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; --i) {
        for (int x : vv[i]) {
        ans.push_back(x);
        if (ans.size() == k) break;
    }
}
        return ans;
    }
};
