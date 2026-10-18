class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dist;
            for(const auto &i: flights){
                int u=i[0],v=i[1],wt=i[2];
                if(dist[u]==1e9) continue;
                if(dist[u]+wt<temp[v]){
                    temp[v]=dist[u]+wt;
                }
            }
            dist=temp;
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
