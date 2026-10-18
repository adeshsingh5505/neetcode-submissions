class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        if(s.size()<nums.size()) return 1;
        return 0;
    }
};