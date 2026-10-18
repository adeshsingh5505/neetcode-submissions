class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int n=points.size();
        vector<bool> visited(n+1,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        pq.push({0,{0,-1}});
        int sum=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second.first;
            if(visited[node]) continue;
            sum+=p.first;
            visited[node]=1;
            for(auto i:adj[node]){
                if(!visited[i.first]){
                    pq.push({i.second,{i.first,node}});
                }
            }
        }
        return sum;
    }
};
