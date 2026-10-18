class Solution {
vector<vector<int>> vt;
public:

    string encode(vector<string>& strs) {
        for(int i=0;i<strs.size();i++){
            vector<int> v;
            for(int j=0;j<strs[i].size();j++){
                v.push_back(strs[i][j]-'a');
            }
            vt.push_back(v);
        }
        for(int i=0;i<vt.size();i++){
            for(int j:vt[i]) cout<<j<<" ";
            cout<<endl;
        }
        return "";
    }

    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0;i<vt.size();i++){
            string ans="";
            for(int j:vt[i]){
                ans+=(j+'a');
            }
            res.push_back(ans);
        }
        return res;
    }
};
