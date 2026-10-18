class Solution {
    bool checkCycle(unordered_map<char,list<char>> &adj,vector<int> &visited, char ch){
        visited[ch-'a']=2;
        for(auto i:adj[ch]){
            if(visited[i-'a']==0){
                visited[i-'a']=2;
                if(checkCycle(adj,visited,i)) return 1;
            }
            if(visited[i-'a']==2) return 1;
        }
        visited[ch-'a']=1;
        return 0;
    }
string st="";
    void dfsTopo(unordered_map<char,list<char>> &adj,unordered_map<char,bool> &visited, char ch){
        visited[ch]=1;
        for(auto i:adj[ch]){
            if(!visited[i]){
                dfsTopo(adj,visited,i);
            }
        }
        st+=ch;
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,list<char>> adj;
        unordered_map<char,bool> visited;
        for(auto i:words){
            for(auto j:i){
                adj[j];
                visited[j]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            int size=min(words[i].size(),words[i+1].size());
            if (words[i].substr(0, size) == words[i + 1].substr(0, size) && words[i].size() > words[i + 1].size()) {
                return "";
            }
            for(int j=0;j<size;j++){
                if(words[i][j]!=words[i+1][j]){
                    adj[words[i][j]].push_back(words[i+1][j]);
                    break;
                }
            }
        }
        vector<int> cvisited(26,0);
        st.clear();
        for(auto i:words){
            for(auto j: i){
                if(!cvisited[j-'a'] && checkCycle(adj,cvisited,j)) return "";
                if(!visited[j])
                dfsTopo(adj,visited,j);
            }
        }
        reverse(st.begin(),st.end());
        return st;
        
    }
};
