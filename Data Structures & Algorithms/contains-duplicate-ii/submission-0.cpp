class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int s=0;
        int n=nums.size();
        while(s<n){
            for(int i=s+1;i<=s+k && i<n;i++){
                if(nums[i]==nums[s]){
                    cout<<s<<" "<<i<<endl;
                    return 1;
                }
            }
            s++;
        }
        return 0;
    }
};