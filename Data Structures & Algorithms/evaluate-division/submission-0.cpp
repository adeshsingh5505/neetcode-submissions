class Solution {
private:
    double bfs(string src, string dest, unordered_map<string,vector<pair<string,double>>> &adj){
        if (!adj.count(src) || !adj.count(dest)) return -1.0;
        if (src == dest) return 1.0;
        unordered_map<string,bool> visited;
        visited[src]=1;
        queue<pair<string,double>> q;
        q.push({src,1});
        while(!q.empty()){
            auto [node,weight]=q.front();
            q.pop();
            if(node==dest) return weight;
            for(auto& nei:adj[node]){
                if(!visited[nei.first]){
                    q.push({nei.first,weight*nei.second});
                    visited[nei.first]=1;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,(1.0/values[i])});
        }
        vector<double> ans;
        for(auto& q: queries){
            ans.push_back(bfs(q[0],q[1],adj));
        }
        return ans;
    }
};