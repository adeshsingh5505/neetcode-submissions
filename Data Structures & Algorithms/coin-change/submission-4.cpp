class Solution {
private:
    int solve(vector<int>& coins, int amount, int idx){
        if(idx==0){
            if(amount%coins[idx]==0) return (amount/coins[idx]);
            return 1e9;
        }
        //take
        int t=1e9;
        if(coins[idx]<=amount)
        t = 1 + solve(coins,amount-coins[idx],idx);
        //not take
        int nt=solve(coins,amount,idx-1);
        return min(nt,t);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int t=solve(coins,amount,n-1);
        if(t==1e9) return -1;
        return t;
    }
};
