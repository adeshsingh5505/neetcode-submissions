class Solution {
private:
    int solve(vector<int>& prices,int b, int s, int n){
        if(s>=n||b>=n || s<b) return 0;
        //deal done, proceed next
        int k=(prices[s]-prices[b])+solve(prices,s+2,s+3,n);
        //deal not done, explore next
        int r=solve(prices,b,s+1,n);
        //skip buying day
        int l=solve(prices,b+1,s,n);
        return max(l,max(k,r));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(prices,0,1,n);
    }
};
