class Solution {
private:
    int pivot(vector<int> nums){
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]<nums[0]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return e;
    }
    int bs(vector<int> nums, int target, int s, int e){
        if(s>e) return -1;
        int mid=s+(e-s)/2;
        if(nums[mid]==target)return mid;
        if(nums[mid]<target)s=mid+1;
        if(nums[mid]>target)e=mid-1;
        return bs(nums,target,s,e);
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=pivot(nums);
        cout<<k;
       // if(nums[k]==target) return k;
        if(target<nums[k]&&nums[0]>target) return bs(nums,target,k+1,n-1);
        else return bs(nums,target,0,k);
    }
};
