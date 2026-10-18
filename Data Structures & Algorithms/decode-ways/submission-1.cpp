class Solution {
private:
    void solve(string s, int idx, int &cnt){
        if(idx>=s.size()){
            cnt++;
            return;
        }
        //take 1 digit
        if(s[idx]!='0')
        solve(s,idx+1,cnt);
        //take 2 digit
        if(idx+1<s.size() && stoi(s.substr(idx,2))>=10 && stoi(s.substr(idx,2))<=26 ){
            solve(s,idx+2,cnt);
        }

    }
public:
    int numDecodings(string s) {
        int cnt=0;
        solve(s,0,cnt);
        return cnt;
    }
};
