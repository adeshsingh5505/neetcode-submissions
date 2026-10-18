class Solution {
int cnt=0;
private:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,queue<pair<int,int>> q, int n, int l){
        int dr[]={-1,0,0,1};
        int dc[]={0,-1,1,0};
        while(!q.empty()){
            bool rotted=0;
            int s=q.size();
            while(s--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rr=r+dr[i];
                int cc=c+dc[i];
                if(rr>=0 && c>=0 && rr<n && cc<l && grid[rr][cc]==1 && !visited[rr][cc]){
                    q.push({rr,cc});
                    visited[rr][cc]=1;
                    grid[rr][cc]=2;
                    rotted=1;
                }
            }
            }
            if(rotted)
            cnt++;
            cout<<cnt<<" ";
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),l=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(l,0));
        int i=0,one=0;
        while(i<n){
            for(int j=0;j<l;j++){
                if(grid[i][j]==2 && !visited[i][j]){
                    q.push({i,j});
                }
                if(grid[i][j]==1) one++;
            }
            i++;
        }
        bfs(grid,visited,q,n,l);
        int k=0;
        while(k<n){
            for(int j=0;j<l;j++){
                if(grid[k][j]==1) return-1;
            }
            k++;
        }
        return cnt;
    }
};
