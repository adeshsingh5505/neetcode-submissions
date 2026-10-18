class Solution {
//simulation approach
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') star.push(i);
            if(s[i]=='(') open.push(i);
            if(s[i]==')'){
                if(open.empty() && !star.empty()){
                    star.pop();
                }
                else if(!open.empty()){
                    open.pop();
                }
                else return 0;
            }
        }
        while(!open.empty() && !star.empty()){
            if(open.top()>star.top()){
                return 0;
            }
            open.pop();star.pop();
        }
        return open.empty();
    }
};
