class Solution {
private:    
    int dfs(vector<vector<int>>& grid, int r, int c, int n, int m,
    vector<vector<int>> &visited){
        if(r<0 || c<0 ||r>=n ||c>=m ||grid[r][c]==0) return 1;
        if(visited[r][c]) return 0;
        visited[r][c]=1;
        return dfs(grid,r+1,c,n,m,visited)+dfs(grid,r,c+1,n,m,visited)+
                dfs(grid,r,c-1,n,m,visited)+dfs(grid,r-1,c,n,m,visited);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j,n,m,visited);
                }
            }
        }
        return 0;
    }
};