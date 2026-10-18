class Solution {
int cnt=0;
private:
    void solve(int r, int c, vector<vector<int>> visited, int n){
        if(r==n-1){
            cnt++;
            return;
        }
        //traverese vertical
        for (int i=0;i<n;i++){
            //if(visited[i][c]==1 || visited[r][i]==1) return;
             visited[i][c]=2;
             visited[r][i]=2;
        }
        //traverse horizontal
        for (int i=0;i<n;i++){
            //if(visited[r][i]==1) return;
            visited[r][i]=2;
        }
        //traverse diagonals
        int dr = r, dc = c;
        while(dr<n && dc<n && dr>=0 && dc>=0){
            //if(visited[dr][dc]==1) return;
            visited[dr--][dc++]=2;
        }
        dr = r, dc = c;
        while(dr<n && dc<n && dr>=0 && dc>=0){
            //if(visited[dr][dc]==1) return;
            visited[dr++][dc--]=2;
        }
        dr = r, dc = c;
        while(dr<n && dc<n && dr>=0 && dc>=0){
            //if(visited[dr][dc]==1) return;
            visited[dr++][dc++]=2;
        }
        dr = r, dc = c;
        while(dr<n && dc<n && dr>=0 && dc>=0){
            //if(visited[dr][dc]==1) return;
            visited[dr--][dc--]=2;
        }
        
        if(r+1<n){
            for(int i=0;i<n;i++){
                if(visited[r+1][i]!=1 && visited[r+1][i]!=2){
                    auto newV=visited;
                    newV[r+1][i]=1;
                    solve(r+1,i,newV,n);
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        cnt=0;
        for(int i=0;i<n;i++){
            vector<vector<int>> visited(n,vector<int>(n,0));
            visited[0][i]=1;
            solve(0,i,visited,n);
        }
        return cnt;
    }
};