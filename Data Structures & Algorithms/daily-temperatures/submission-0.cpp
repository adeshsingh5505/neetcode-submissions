class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int fill=0;
            for(int j=i;j<n;j++){
                if(temperatures[j]>temperatures[i]){
                    fill=j-i;
                    break;
                }
            }
            ans[i]=fill;
        }
        return ans;
    }
};
