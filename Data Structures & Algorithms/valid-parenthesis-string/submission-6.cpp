class Solution {
//greedy approach O(N),O(1)
public:
    bool checkValidString(string s) {
        //high:max open
        //low:min open
        int high=0,low=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){ high++;low++;}
            if(s[i]==')'){ high--;low--;}
            if(s[i]=='*'){high++;low--;}
            if(high<0) return 0;
            if(low<0) low=0;
        }
        return low==0;
    }
};
