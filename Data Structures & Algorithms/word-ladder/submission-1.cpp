class Solution {
private:
    int mini=1e9;
    bool check(string s1, string s2){
        if(s1.size()!=s2.size()) return 0;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        if(cnt==1) return 1;
        return 0;
    }
    void bfs(unordered_map<string,list<string>> &adj,unordered_map<string,bool> &visited,string begin,string end){
        queue<pair<string,int>> q;
        q.push({begin,1});
        visited[begin]=1;
        int cnt=0;
        while(!q.empty()){
            string node=q.front().first;
            int level=q.front().second;
            if(end==node) mini=level;
            q.pop();
            for(auto i:adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push({i,level+1});
                    cnt++;
                }
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        mini=1e9;
        wordList.push_back(beginWord);
        unordered_map<string,bool> visited;
        unordered_map<string,list<string>> adj;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            visited[wordList[i]]=false;
            for(int j=i+1;j<n;j++){
                if(check(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        bfs(adj,visited,beginWord,endWord);
        if(mini==1e9) return 0;
        return mini;
    }
};
