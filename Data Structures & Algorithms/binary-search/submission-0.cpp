class Solution {
private:
    int solve(vector<int>& nums, int target, int s, int e){
        int mid=s+(e-s)/2;
        if(s>e) return -1;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target)s=mid+1;
        if(nums[mid]>target)e=mid-1;
        return solve(nums,target,s,e);
    }
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int k=nums.size()-1;
        return solve(nums,target,i,k);
    }
};
