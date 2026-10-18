class Solution {
    bool canJump(int i, int j, int mini, int maxi, string &s){
        int len = s.size();
        if( i+mini <= j && j <= min(i+maxi,len-1) && s[j]=='0') return 1;
        return 0;
    }
    void bfs(unordered_map<int,vector<int>> &adj, vector<int> &visited, int src){
        queue<int> q;
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& n:adj[node]){
                if(!visited[n]){
                    visited[n]=1;
                    q.push(n);
                }
            }
        }
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        unordered_map<int,vector<int>> adj;
        int n = s.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(canJump(i,j,minJump,maxJump,s)){
                    adj[i].push_back(j);
                }
            }
        }
        // for(auto& i: mp){
        //     cout<<i.first<<":";
        //     for(auto& j:i.second) cout<<j<<" ";
        //     cout<<endl;
            
        // }
        vector<int> visited(n+1,0);
        bfs(adj,visited,0);
        for(auto& v:visited) cout<<v<<" ";
        return visited[n-1];
    }
};