class Solution {
private:
    
public:
    bool stoneGame(vector<int>& piles) {
        int alice=0,bob=0;
        int n=piles.size();
        int i=0,j=n-1;
        for(int k=0;k<n/2;k++){
            if(piles[i]>=piles[j]){
                alice+=piles[i];
                bob+=piles[j];
            }
            else{
                alice+=piles[j];
                bob+=piles[i];
            }
            cout<<alice<<" "<<bob<<endl;
            i++;j--;
        }
        return alice>bob;
    }
};