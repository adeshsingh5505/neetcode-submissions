class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(const auto& i: nums) mp[i]++;
        vector<int>ans;
        for(const auto& i:mp){
            if(i.second>(n/3)) ans.push_back(i.first);
        }
        return ans;
    }
};