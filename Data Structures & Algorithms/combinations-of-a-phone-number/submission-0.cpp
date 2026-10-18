class Solution {
vector<string> ans;
private:
    void solve(vector<vector<char>> &v, string res, string digits, int idx){
        if(res.size()==digits.size()){
            ans.push_back(res);
            return;
        }
        
            int d=(digits[idx]-'0');
            for(int j=0;j<v[d].size();j++){
                res+=v[d][j];
                solve(v,res,digits,idx+1);
                res.pop_back();
            }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        ans.clear();
        vector<vector<char>> v = {{},{},{'a', 'b', 'c'},{'d', 'e', 'f'},
        {'g', 'h', 'i'},{'j', 'k', 'l'},{'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},{'t', 'u', 'v'},{'w', 'x', 'y', 'z'}
        };
        solve(v,"",digits,0);
        return ans;
    }
};
