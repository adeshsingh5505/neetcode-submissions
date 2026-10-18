class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=1;
        int maxi=0;
        int n=prices.size();
        while(j<n){
            maxi=max(maxi,prices[j]-prices[i]);
            if(prices[i+1]<prices[i])i++;
            j++;
        }
        cout<<i<<j<<endl;
        while(i<n){
            cout<<prices[n-1]<<" "<<prices[i]<<" "<<prices[n-1]-prices[i]<<endl;
            maxi=max(maxi,prices[n-1]-prices[i]);
            i++;
        }
        return maxi;
    }
};
