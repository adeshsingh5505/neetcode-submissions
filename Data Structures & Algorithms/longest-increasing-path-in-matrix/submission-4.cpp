class Solution {
int maxi=1;
vector<int> dr={-1,1,0,0};
vector<int> dc={0,0,1,-1};
private:
    void dfs(vector<vector<int>>& matrix, int i, int j, int n,int m, int cnt){
        if(i>=n || j>=m || i<0 || j<0){
            maxi=max(maxi,cnt);
            return;
        }
        for(int k=0;k<4;k++){
            int rr=i+dr[k];
            int cc=j+dc[k];
            if(rr<n && cc<m && rr>=0 && cc>=0 && matrix[rr][cc]>matrix[i][j]){
                dfs(matrix,rr,cc,n,m,cnt+1);
            }
            else{
                maxi=max(maxi,cnt);
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=1;
                dfs(matrix,i,j,n,m,cnt);
            }
        }
        return maxi;
    }
};
