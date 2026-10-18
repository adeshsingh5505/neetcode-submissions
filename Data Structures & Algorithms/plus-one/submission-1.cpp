class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string st="";
        for(int i=0;i<digits.size();i++){
            st+=(digits[i]+48);
        }
        long long x=stol(st);
        x++;
        st=to_string(x);
        vector<int> ans;
        for(int i=0;i<st.size();i++){
            ans.push_back(st[i]-48);
        }
        return ans;
    }
};
