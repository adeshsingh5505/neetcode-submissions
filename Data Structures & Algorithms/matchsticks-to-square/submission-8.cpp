class Solution {
private:
    bool solve(vector<int>& matchsticks,int l,int r, int t, int b, int idx, int side){
        if (idx == matchsticks.size()) {
            return (l == side && r == side && t == side && b == side);
        }
        if(l>side||r>side||t>side||b>side) return 0;
        //left
        bool ll=solve(matchsticks,l+matchsticks[idx],r,t,b,idx+1,side);
        //right
        bool rr=solve(matchsticks,l,r+matchsticks[idx],t,b,idx+1,side);
        //top
        bool tt=solve(matchsticks,l,r,t+matchsticks[idx],b,idx+1,side);
        //bottom
        bool bb=solve(matchsticks,l,r,t,b+matchsticks[idx],idx+1,side);

        return ll||rr||tt||bb;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        //4 decesion left,right,top,bottom
        int total=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total%4!=0) return 0;
        int side=total/4;
        return solve(matchsticks,matchsticks[0],0,0,0,1,side);
    }
};