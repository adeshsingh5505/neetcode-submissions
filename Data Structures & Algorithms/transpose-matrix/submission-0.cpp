class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> ans(m);
        int r=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[r].push_back(matrix[j][i]);
            }
            r++;
        }
        return ans;
    }
};