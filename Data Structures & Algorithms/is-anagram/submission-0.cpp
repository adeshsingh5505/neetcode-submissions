class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0),b(26,0);
        if(s.size()!=t.size()) return 0;
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(a[i]!=b[i])return 0;
        }
        return 1;
    }
};
