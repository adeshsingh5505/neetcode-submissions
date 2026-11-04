
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &token : tokens) {

            if (token == "*") {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                st.push(t2 * t1);
            }
            else if (token == "+") {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                st.push(t2 + t1);
            }
            else if (token == "-") {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                st.push(t2 - t1);
            }
            else if (token == "/") {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                st.push(t2 / t1);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
