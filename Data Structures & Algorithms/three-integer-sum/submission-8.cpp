class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int s=i+1,e=n-1;
            int rem=nums[i]*-1;
            while(s<e){
                if(nums[s]+nums[e]==rem){
                    st.insert({nums[i],nums[s],nums[e]});
                    s++;e--;
                } else if(nums[s]+nums[e]<rem){
                    s++;
                } else if(nums[s]+nums[e]>rem){
                    e--;
                }
            }
        }
        for(auto i: st) ans.push_back(i);
        return ans;
    }
};
