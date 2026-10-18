class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int p1=0,p2=0;
        int s1=word1.size(),s2=word2.size();
        while(p1<s1 && p2<s2){
            res+=word1[p1++];
            res+=word2[p2++];
        }
        if(p2<s2) res+=word2.substr(p2);
        if(p1<s1) res+=word1.substr(p1);
        return res;
    }
};