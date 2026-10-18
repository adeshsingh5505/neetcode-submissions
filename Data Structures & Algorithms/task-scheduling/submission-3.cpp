class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for(auto i:tasks){
            hash[i-'A']++;
        }
        int maxf=*max_element(hash.begin(),hash.end());
        int fc=count(hash.begin(),hash.end(),maxf);
        int min_time=(maxf-1)*(n+1)+fc;
        return max((int)tasks.size(),min_time);
    }
};
