class Solution {
private:
    bool dfsCD(unordered_map<int,list<int>> &adj,vector<int> &visited, int src){
        visited[src]=2;
        for(int i:adj[src]){
            if(visited[i]==0){
                visited[i]=2;
                if(dfsCD(adj,visited,i)) return 1;
            }
            else if(visited[i]==2) return 1;
        }
        visited[src]=1;
        return 0;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,list<int>> adj;
        vector<int> visited(n+1,0);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0 && dfsCD(adj,visited,i)) return 0;
        }
        return 1;
    }
};
