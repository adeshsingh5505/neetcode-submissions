class Solution {
int n;
private:
    bool solve(unordered_map<string,vector<string>> &adj,vector<string> &ans,string src){
        if(ans.size()==n+1) return 1;
        if(adj[src].empty()) return 0;
        vector<string> temp=adj[src];
        for(int i=0;i<temp.size();i++){
            string v=temp[i];
            adj[src].erase(adj[src].begin()+i);
            ans.push_back(v);
            if(solve(adj,ans,v)) return 1;
            adj[src].insert(adj[src].begin()+i,v);
            ans.pop_back();
        }
        return 0;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n=tickets.size();
        sort(tickets.begin(),tickets.end());
        unordered_map<string,vector<string>> adj;
        for(auto i: tickets){
            adj[i[0]].push_back(i[1]);
        }
        vector<string> ans={"JFK"};
        bool p=solve(adj,ans,"JFK");
        return ans;
    }
};
