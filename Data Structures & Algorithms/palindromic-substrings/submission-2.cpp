class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0,cnt2=0;
        int i=0;
        while(i<s.size()){
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
            i++;
        }

        return cnt;
    }
};
