class Solution {
private:
    bool bs(vector<int> &nums, int target){
        int r=nums.size()-1;
        int l=0;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(target==nums[mid]) return 1;
            if(nums[mid]==nums[r] && nums[mid]==nums[l]){
                l++;
                r--;
            }
            //left half sorted
            else if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            //right half sorted
            else{
                if(nums[mid]<target && target<=nums[r]){
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return 0;
    }
public:
    bool search(vector<int>& nums, int target) {
        return bs(nums,target);
    }
};