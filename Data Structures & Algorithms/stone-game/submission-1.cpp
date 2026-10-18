class Solution {
private:
    bool solve(vector<int> &piles, int i, int j, int alice, int bob){
        if(i>j) return alice>bob;
        bool p=solve(piles,i+1,j-1,alice+piles[i],bob+piles[j]);
        bool q=solve(piles,i+1,j-1,alice+piles[j],bob+piles[i]);
        return p||q;
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int alice=0,bob=0;
        return solve(piles,0,n-1,alice,bob);
    }
};