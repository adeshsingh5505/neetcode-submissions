class Solution {
public:
    int mySqrt(int x) {
        int l=1,r=x;
        int mid=l+(r-l)/2;
        int ans=0;
        while(l<=r){
            if((long long)mid*mid==(long long)x) return mid;
            if((long long)mid*mid<(long long)x){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
            mid=l+(r-l)/2;
        }
        return ans;
    }
};