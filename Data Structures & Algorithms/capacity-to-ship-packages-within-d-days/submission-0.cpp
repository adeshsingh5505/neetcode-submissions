class Solution {
private:
    bool counter(vector<int> &weights,int limit,int days){
        int sum=0,cnt=1;
        for(auto& w: weights){
            if(sum+w>limit){
                cnt++;
                sum=0;
            }
            sum+=w;
        }
        return cnt<=days;
    }
    int bs(vector<int>& weights, int days,int mini, int maxi){
        int l=mini,r=maxi;
        int ans=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(counter(weights,mid,days)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=accumulate(weights.begin(),weights.end(),0);
        int mini=*max_element(weights.begin(),weights.end());
        int ans=bs(weights,days,mini,maxi);
        return ans;
    }
};