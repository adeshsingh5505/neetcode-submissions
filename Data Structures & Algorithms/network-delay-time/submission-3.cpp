class Solution {
private:
    void dijksh(unordered_map<int,list<pair<int,int>>> &adj,vector<int> &wt, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        wt[src]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int w=pq.top().first;
            // cout<<w<<" "<<node<<endl;
            //if(w>wt[node]) continue;
            pq.pop();
            for(auto i:adj[node]){
                wt[i.second]=min(wt[i.second],w+i.first);
                if(wt[i.second]==w+i.first)
                pq.push({wt[i.second],i.second});
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({w,v});
        }
        vector<int> wt(n+1,INT_MAX);
        dijksh(adj,wt,k);
        int maxi=-1;
        for(int i=1;i<wt.size();i++){
            if(wt[i]==INT_MAX) return -1;
            else maxi=max(maxi,wt[i]);
        }
        return maxi;
    }
};
