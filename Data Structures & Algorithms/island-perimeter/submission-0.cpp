class Solution {
private:
    vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
    int checker(vector<vector<int>> &grid, int r, int c, int n, int m){
        int cnt=0;
        for(int i=0;i<4;i++){
            int rr=r+dx[i];
            int cc=c+dy[i];
            int f=4;
            if(rr<n && cc<m && rr>=0 && cc>=0){
                if(grid[rr][cc]==1) cnt++;
            }
        }
        return 4-cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sum+=checker(grid,i,j,n,m);
                }
            }
        }
        return sum;
    }
};