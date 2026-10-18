class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> visitor(n+1,0),visited(n+1,0);
        for(auto& i: trust){
            visitor[i[0]]++;
            visited[i[1]]++;
        }

        vector<int>ans;

        for(int i=1;i<=n;i++){
            if(visited[i]==n-1 && visitor[i]==0) {
                ans.push_back(i);
            }
        }
        if(ans.size()==0 || ans.size()>1) return -1;
        return ans[0];
    }
};