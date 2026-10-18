class Solution {
private:
    bool solve(vector<vector<char>>& board, string word,int i, int j, int n, int m,int idx,vector<vector<int>> &visited){
        if(i>=n || j>=m || i<0 || j<0 || word[idx]!=board[i][j] || visited[i][j]) return 0;
        visited[i][j]=1;
        if(idx == word.size() - 1) return true;
        bool f=(solve(board,word,i+1,j,n,m,idx+1,visited)||
                solve(board,word,i-1,j,n,m,idx+1,visited)||
                solve(board,word,i,j+1,n,m,idx+1,visited)||
                solve(board,word,i,j-1,n,m,idx+1,visited));
        visited[i][j]=0;
        return f;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(board,word,i,j,n,m,0,visited)) return 1;
            }
        }
        return 0;
    }
};
