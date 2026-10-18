class Solution {
private:
    int solve(string s, string t, int idx, string ans){
        if(ans==t) return 1;
        if(idx>=s.size()||ans.size()>t.size()) return 0;
        
        //take
        ans+=s[idx];
        int ta=solve(s,t,idx+1,ans);
        ans.pop_back();
        //not take
        int nt=solve(s,t,idx+1,ans);

        return ta+nt;
    }
public:
    int numDistinct(string s, string t) {
        return solve(s,t,0,"");
    }
};
