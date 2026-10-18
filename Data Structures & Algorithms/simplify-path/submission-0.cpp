class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr="";
        for(auto& c:path+"/"){
            if(c=='/'){
                if(curr==".."){
                    if(!st.empty()) st.pop();
                }
                else if(curr!="."&&curr!=""){
                    st.push(curr);
                }
                curr="";
            } else curr+=c;
        }
        //cout<<st.top();
        string ans="";
        while(!st.empty()){
            ans='/'+st.top()+ans;
            st.pop();
        }
        if(ans.size()==0) return "/";
        return ans;
    }
};