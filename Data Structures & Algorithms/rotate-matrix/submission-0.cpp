class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        int i=0;
        while(i<n){
            for(int j=0;j<n;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
            i++;
        }
        matrix=ans;
    }
};
