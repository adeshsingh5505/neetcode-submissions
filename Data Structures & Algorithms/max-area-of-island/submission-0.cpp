class Solution {
private:
    int maxi=0;
    void bfs(vector<vector<int>> grid,vector<vector<int>>& visited, int i, int j ,int n ,int l){
        queue<pair<int,int>> q;
        int cnt=1;
        q.push({i,j});
        visited[i][j]=1;
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int u=0;u<4;u++){
                int rr=r+dr[u];
                int cc=c+dc[u];
                if(cc>=0 && rr>=0 && rr<n && cc<l && !visited[rr][cc] && grid[rr][cc]==1){
                    visited[rr][cc]=1;
                    cnt++;
                    q.push({rr,cc});
                }
            }
            cout<<cnt<<" ";
        }
        maxi=max(maxi,cnt);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),l=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(l,0));
        int i=0;
        while(i<n){
            for(int j=0;j<l;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    bfs(grid,visited,i,j,n,l);
                }
            }
            i++;
        }
        return maxi;
    }
};
