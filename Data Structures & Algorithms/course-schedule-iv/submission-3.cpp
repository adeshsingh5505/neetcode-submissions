class Solution {
private:
    vector<int> solve(unordered_map<int,list<int>> &adj,int src,int nc){
        vector<int> visited(nc,0);
        queue<int> q;
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& n: adj[node]){
                if(!visited[n]){
                    visited[n]=1;
                    q.push(n);
                }
            }
        }
        return visited;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, 
    vector<vector<int>>& queries) {
        unordered_map<int,list<int>> adj;
        for(auto& i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> ans;
        vector<vector<int>> v(numCourses,vector<int>(numCourses,0));
        for(int i=0;i<numCourses;i++){
            v[i]=solve(adj,i,numCourses);
        }
        for(auto& i: queries){
            if(v[i[0]][i[1]]==0) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};