class Solution {
private:
    void cnrt(string s, long long &x){
        stack<int> st;
        for(int i=0;i<s.size();i++){
            //cout<<s[i]-48<<" ";
            st.push(s[i]-48);
        }
        long long e=0;
        long long cnt=0;
        while(!st.empty()){
            int a=st.top();
            int b=pow(10,cnt);
            e+=a*b;
            cnt++;
            st.pop();
        }
        x=e;
    }
public:
    string multiply(string num1, string num2) {
        long long n1,n2;
        cout<<num1[0]-48<<endl;
        cnrt(num1,n1);
        cnrt(num2,n2);
        long long s=n1*n2;
        string ans="";
        return to_string(s);
    }
};
