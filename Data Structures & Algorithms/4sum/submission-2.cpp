class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i]==nums[i-1]){ 
                continue;
                }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
            
            long long sum = (long long)nums[i] + nums[j];
            int l=j+1,r=n-1;
            while(l<r){
                if(l>j+1 && nums[l]==nums[l-1]) {
                    l++;
                    continue;
                    }
                if(r<n-1 && nums[r]==nums[r+1]) {
                    r--;
                    continue;
                    }
                long long sum2 = (long long)nums[l] + nums[r];
                if(sum+sum2==target){
                    ans.push_back({nums[i],nums[l],nums[r],nums[j]});
                    l++;
                    r--;
                } else if(sum+sum2<target){
                    l++;
                } else{
                    r--;
                }
            }
            }
        }
        return ans;
    }
};