class Solution {
private:
    bool bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,int> &parent, int src){
        visited[src]=1;
        parent[src]=-1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(!visited[i]){
                    parent[i]=node;
                    visited[i]=1;
                    q.push(i);
                }
                else if(visited[i] && parent[node]!=i){
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //add edges and then check for cycle...
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            unordered_map<int,bool> visited;
            unordered_map<int,int> parent;
            if(bfs(adj,visited,parent,u))  return edges[i];
        }
        return {};
    }
};
