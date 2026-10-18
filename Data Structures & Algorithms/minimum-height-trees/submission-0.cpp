class Solution {
private:
    int solve(unordered_map<int,vector<int>> &adj,int root,int n){
        int height=0;
        vector<int> visited(n,0);
        visited[root]=1;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                for(auto n:adj[node]){
                    if(!visited[n]){
                        visited[n]=1;
                        q.push(n);
                    }
                }
            }
            height++;
        }
        return height;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& e:edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            //root->i
            cout<<i<<" "<<solve(adj,i,n)<<endl;
            mp.push({solve(adj,i,n),i});
        }
        vector<int> ans;
        auto top=mp.top();
        mp.pop();
        ans.push_back(top.second);
        while(!mp.empty()){
            auto t=mp.top();
            mp.pop();
            if(t.first<=top.first) ans.push_back(t.second);
        }
        return ans;
    }
};