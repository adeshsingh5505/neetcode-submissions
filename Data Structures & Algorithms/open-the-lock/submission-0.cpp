class Solution {
private:
    vector<string> children(string combi){
        vector<string> ans;
        for(int i=0;i<4;i++){
            int n = combi[i]-'0';
            combi[i]=char(((n+1)%10)+'0');
            ans.push_back(combi);
            combi[i]=char(((n-1+10)%10)+'0');
            ans.push_back(combi);
            combi[i]=n+'0';
        }
        return ans;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> dmap;
        for(auto& i: deadends){
            dmap[i]=1;
        }
        if(dmap["0000"]) return -1;
        if(target=="0000") return 1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        dmap["0000"] = 1;
        while(!q.empty()){
            string combi = q.front().first;
            int n= q.front().second;
            q.pop();
            vector<string> childs = children(combi);
            for(auto& c: childs){
                if(!dmap[c]){
                if(c==target) return n+1;
                dmap[c]=1;
                q.push({c,n+1});
                }
            }
        }
        return -1;
    }
};