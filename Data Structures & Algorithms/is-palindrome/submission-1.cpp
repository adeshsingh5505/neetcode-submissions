class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'||s[i]>='0' && s[i]<'9') st+=tolower(s[i]);
        }
        cout<<st<<endl;
        int i=0,j=st.size()-1;
        while(i<j){
            if(st[i]!=st[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};
