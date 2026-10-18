class Solution {
private:
    int pivot(vector<int> nums,int s, int e){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]<nums[e]){
                e=mid;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return e;
    }
public:
    int findMin(vector<int> &nums) {
        return nums[pivot(nums,0,nums.size()-1)];
    }
};
