class Solution {
private:
    void bfs(queue<pair<int,int>> q,vector<vector<int>>& grid,vector<vector<int>>& visited, int n, int l){
        int dist=0;
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while(!q.empty()){
            int s=q.size();
        while(s--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rr=r+dr[i],cc=c+dc[i];
                if(rr>=0 && cc>=0 && rr<n && cc<l && !visited[rr][cc] && grid[rr][cc]!=-1){
                    visited[rr][cc]=1;
                    grid[rr][cc]=dist+1;
                    q.push({rr,cc});
                }
            }
        }
        dist++;
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //start bfs from every treasure chest
        queue<pair<int,int>> q;
        int n=grid.size(),l=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(l,0));
        int i=0;
        while(i<n){
            for(int j=0;j<l;j++){
                if(grid[i][j]==0){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
            i++;
        }
        bfs(q,grid,visited,n,l);
    }
};
