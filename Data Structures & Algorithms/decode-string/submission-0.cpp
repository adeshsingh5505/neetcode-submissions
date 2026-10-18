class Solution {
private:
    string solve(int k, string s){
        string res="";
        while(k--){
            res+=s;
        }
        return res;
    }
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto& ch:s){
            string chStr(1, ch);
            if(chStr!="]"){
                st.push(chStr);
            } else{
                string sub="";
                while(st.top()!="["){
                    sub=st.top()+sub;
                    st.pop();
                }
                st.pop();
                string i="";
                while(!st.empty()&&isdigit(st.top()[0])){
                    i=st.top()+i;
                    st.pop();
                }
                int k = stoi(i);
                st.push(solve(k,sub));
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};