class Solution {
//TC=O(nlogn)
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> st;
        for(auto i: nums){
            if(i>0) st.insert(i);
        }
        for(const auto& i: st) pq.push(i);
        int lowest=1;
        while(!pq.empty()){
            if(pq.top()!=lowest) return lowest;
            pq.pop();
            lowest++;
        }
        return lowest;
    }
};