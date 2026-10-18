class Solution {
int pcnt=0;
private:
    void solve(unordered_map<int,list<int>> adj,unordered_map<int,int> &visited, int src){
        unordered_map<int,int> parent;
        queue<int> q;
        visited[src]=1;
        parent[src]=-1;
        pcnt++;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i: adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    parent[i]=node;
                    q.push(i);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        pcnt=0;
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int> visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                solve(adj,visited,i);
            }
        }
        return pcnt;
    }
};
