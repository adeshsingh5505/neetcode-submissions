class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        nums1.erase(nums1.begin()+m,nums1.begin()+m+n);
        int p1=0,p2=0;
        int n1=m,n2=n;
        while(p1<n1 && p2<n2){
            if(nums1[p1]<nums2[p2]){
                res.push_back(nums1[p1++]);
            }
            else{
                res.push_back(nums2[p2++]);
            }
        }
        if(p1<n1){
            while(p1<n1){
                res.push_back(nums1[p1++]);
            }
        }
        if(p2<n2){
            while(p2<n2) res.push_back(nums2[p2++]);
        }
        nums1.clear();
        for(auto i: res){
            nums1.push_back(i);
        }
    }
};