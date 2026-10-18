class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;
        for(auto i:queries){
            int mini=1e9;
            for(auto j:intervals){
                if(i<=j[1] && i>=j[0]){
                    mini=min(mini,j[1]-j[0]+1);
                }
            }
            if(mini==1e9) mini=-1;
            ans.push_back(mini);
        }
        return ans;
    }
};
