class Solution {
int pcnt=0;
private:
    bool bfsCD(unordered_map<int,list<int>> adj,unordered_map<int,int> &visited, int src){
        unordered_map<int,int> parent;
        queue<int> q;
        visited[src]=1;
        parent[src]=-1;
        pcnt++;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    parent[i]=node;
                    q.push(i);
                }
                else if(parent[node]!=i){
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //cycle detection in undirected graph
        pcnt=0;
        unordered_map<int,list<int>> adj;
        unordered_map<int,int> visited;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
            if(!visited[i] && bfsCD(adj,visited,i)) return 0;
        
        if(pcnt>1) return 0;
        return 1;
    }
};
