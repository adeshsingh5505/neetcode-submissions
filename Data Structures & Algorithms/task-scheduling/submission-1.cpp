class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for(auto i:tasks){
            hash[i-'A']++;
        }
        int maxf=*max_element(hash.begin(),hash.end());
        int fc=count(hash.begin(),hash.end(),maxf);
        int part_count=maxf-1;
        int part_length=n;
        int empty_slot=part_count*part_length+fc+maxf-1;
        return max((int)tasks.size(),empty_slot);
    }
};
