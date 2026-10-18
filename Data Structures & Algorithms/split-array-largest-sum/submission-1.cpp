class Solution {
private:
    bool solve(vector<int> &nums, int mid, int k){
        int sum=0;
        int t=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                t++;
                if(t>k) return 0;
                sum=nums[i];
            }
        }
        return 1;
    }
    int bs(vector<int> &nums, int l, int r, int k){
        int res = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(solve(nums,mid,k)){
                res = mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return res;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        return bs(nums,l,r,k);
    }
};