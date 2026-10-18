class Solution {
public:
    int climbStairs(int n) {
        int t1=0,t2=1,ans=0;
        for(int i=1;i<=n;i++){
            ans=t1+t2;
            t1=t2;
            t2=ans;
        }
        return ans;
    }
};
