//store all the possible paths in minHeap{cost,r,c}, 
//then go with the minimum one
class Solution {
private:
    vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
    void solve(vector<vector<int>>& heights,int r, int c, int n, int m, 
    vector<vector<int>>& visited, int &mini,int pathMax,
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> &minHeap){
        if(r==n-1 && c==m-1){
            mini=min(mini,pathMax);
        }
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int rr=dx[i]+r;
            int cc=dy[i]+c;
            if(rr<n && rr>=0 && cc<m && cc>=0 && !visited[rr][cc]){
                int cost=abs(heights[rr][cc]-heights[r][c]);
                minHeap.push({cost,rr,cc});
            }
        }
        if (minHeap.empty()) return;
        auto top=minHeap.top();
        minHeap.pop();
        int newPathMax=max(pathMax,top[0]);
        solve(heights,top[1],top[2],n,m,visited,mini,newPathMax,minHeap);
        visited[r][c]=0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n=heights.size(),m=heights[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       int mini=INT_MAX;
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
       solve(heights,0,0,n,m,visited,mini,0,minHeap);
       return mini;
    }
};