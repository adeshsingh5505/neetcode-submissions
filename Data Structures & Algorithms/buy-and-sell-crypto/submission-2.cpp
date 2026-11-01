class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int> fwd,bwd;
       int n=prices.size();
       int mini=prices[0];
       int maxi=prices[n-1];
       for(int i=0;i<n;i++){
        mini=min(mini,prices[i]);
        fwd.push_back(mini);
       } 
       for(int i=n-1;i>=0;i--){
        maxi=max(maxi,prices[i]);
        bwd.push_back(maxi);
       }
       reverse(bwd.begin(),bwd.end());
       int ans=0;
       for(int i=0;i<n;i++){
        ans=max(ans,bwd[i]-fwd[i]);
       }
       for(auto i: fwd) cout<<i<<" ";
       cout<<endl;
       for(auto i: bwd) cout<<i<<" ";
       cout<<endl;
       return ans;
    }
};
