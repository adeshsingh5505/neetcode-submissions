class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited, int r, int c , int n ,int l){
        if(r<0 || c<0 || r>=n || c>=l || visited[r][c]|| board[r][c]!='O' ){
            return;
        }
        visited[r][c]=1;
        dfs(board,visited,r+1,c,n,l);
        dfs(board,visited,r-1,c,n,l);
        dfs(board,visited,r,c+1,n,l);
        dfs(board,visited,r,c-1,n,l);

    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),l=board[0].size();
        vector<vector<int>> visited(n,vector<int>(l,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,visited,i,0,n,l);
            }
            if(board[i][l-1]=='O'){
                dfs(board,visited,i,l-1,n,l);
            }
        }
        for(int i=0;i<l;i++){
            if(board[0][i]=='O'){
                dfs(board,visited,0,i,n,l);
            }
            if(board[n-1][i]=='O'){
                dfs(board,visited,n-1,i,n,l);
            }
        }
        //flip unvisted O to X
        int i=0;
        while(i<n){
            for(int j=0;j<l;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
            i++;
        }
    }
};
