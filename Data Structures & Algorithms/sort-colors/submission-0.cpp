class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hash(3,0);
        for(auto i: nums){
            hash[i]++;
        }
        nums.clear();
        for(int i=0;i<hash[0];i++) nums.push_back(0);
        for(int i=0;i<hash[1];i++) nums.push_back(1);
        for(int i=0;i<hash[2];i++) nums.push_back(2);
    }
};