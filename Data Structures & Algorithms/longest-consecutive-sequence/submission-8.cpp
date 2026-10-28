class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        //for(auto i: nums) cout<<i<<" ";
        int cnt=1;
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                cnt++;
            } else if( nums[i-1]==nums[i]) continue;
            else{
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};
