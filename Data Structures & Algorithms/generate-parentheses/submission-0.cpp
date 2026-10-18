class Solution {
private:
    void solve(int o, int c, int n, vector<string> &ans, string &st){
        if(c == o && o == n){
            ans.push_back(st);
            return;
        }
        if(c < o){
            st += ')';
            solve(o, c + 1, n, ans, st);
            st.pop_back();  
        }
        if(o < n){
            st += '(';
            solve(o + 1, c, n, ans, st);
            st.pop_back();  
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;
        solve(0, 0, n, ans, st);
        return ans;
    }
};
