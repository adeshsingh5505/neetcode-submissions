class Solution {
private:
    void dfs(vector<vector<int>>& heights,vector<vector<int>> &hash, int r, int c, int n, int m,vector<vector<int>> &visited){
        if(r>=n || c>=m || r<0 || c<0) return;
        if(visited[r][c]) return;
        hash[r][c]++;
        visited[r][c]=1;
        if((r+1)<n && heights[r+1][c]>=heights[r][c])
        dfs(heights,hash,r+1,c+0,n,m,visited);
        if((c-1)>=0 && heights[r][c-1]>=heights[r][c])
        dfs(heights,hash,r,c-1,n,m,visited);

        if((r-1)>=0 && heights[r-1][c]>=heights[r][c])
        dfs(heights,hash,r-1,c,n,m,visited);
        if((c+1)<m && heights[r][c+1]>=heights[r][c])
        dfs(heights,hash,r,c+1,n,m,visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> hash(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        //pacific
        for(int i=0;i<n;i++) dfs(heights,hash,i,0,n,m,visited);
        for(int i=0;i<m;i++) dfs(heights,hash,0,i,n,m,visited);
        //reset visited
        visited.assign(n, vector<int>(m, 0));
        //atlantic
        for(int i=0;i<n;i++) dfs(heights,hash,i,m-1,n,m,visited);
        for(int i=0;i<m;i++) dfs(heights,hash,n-1,i,n,m,visited);

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hash[i][j]>=2)ans.push_back({i,j});
            }
        }
        return ans;
    }
};
