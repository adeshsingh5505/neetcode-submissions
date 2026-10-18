class Solution {
private:
    vector<string> substr;
    string st="";
    bool isPalindrome(string st, int s, int e){
        while(s<=e){
            if(st[e]!=st[s]) return 0;
            s++,e--;
        }
        return 1;
    }
    void solve(string s,vector<vector<string >> &ans, int idx){
        if(idx==s.size()){
            ans.push_back(substr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                substr.push_back(s.substr(idx,i-idx+1));
                solve(s,ans,i+1);
                substr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        st="";
        vector<vector<string>> ans;
        solve(s,ans,0);
        return ans;
    }
};
