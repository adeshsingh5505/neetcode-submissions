class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26,0);
        for(int i=0;i<order.size();i++){
            dict[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string a=words[i],b=words[i+1];
            int len=min(a.size(),b.size());
            bool diff=0;
            for(int j=0;j<len;j++){
                if(dict[a[j]-'a']>dict[b[j]-'a']) return 0;
                else if (dict[a[j] - 'a'] < dict[b[j] - 'a']){
                    diff=1;
                    break;
                }
            }
            if(!diff && b.size()<a.size()) return 0;
        }
        return 1;
    }
};