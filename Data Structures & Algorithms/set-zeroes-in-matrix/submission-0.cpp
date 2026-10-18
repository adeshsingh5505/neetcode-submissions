class Solution {
private:
    void solve(vector<pair<int,int>> pv,vector<vector<int>>& matrix,int n, int l){
        for(int i=0;i<pv.size();i++){
            int r=pv[i].first;
            int c=pv[i].second;
            int tempr=0,tempc=0;

            while(tempr<n){
                    matrix[tempr][c]=0;
                
                tempr++;
            }
                while(tempc<l){
                    matrix[r][tempc]=0;
                    tempc++;
                }
            
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> pv;
        int n=matrix.size(),l=matrix[0].size();
        int i=0;
        while(i<n){
            for(int j=0;j<l;j++){
                if(matrix[i][j]==0){
                    pv.push_back({i,j});
                }
            }
            i++;
        }
        solve(pv,matrix,n,l);
    }
};
