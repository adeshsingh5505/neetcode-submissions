class Solution {
private:
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            nums2.push_back(nums1[i]);
        }
        sort(nums2.begin(),nums2.end());
        int n=nums2.size()-1;
        if((n+1)%2==0) return (nums2[n/2]+nums2[(n/2)+1])/2.0;
        else return (nums2[n/2]);
    }
};
