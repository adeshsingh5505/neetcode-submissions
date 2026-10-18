class Solution {
public:
    int mySqrt(int x) {
        int l=1,r=x;
        int mid=l+(r-l)/2;
        while(l<=r){
            if((long long)mid*mid==(long long)x) return mid;
            if((long long)mid*mid<(long long)x) l=mid+1;
            else r=mid-1;
            mid=l+(r-l)/2;
        }
        return mid-1;
    }
};