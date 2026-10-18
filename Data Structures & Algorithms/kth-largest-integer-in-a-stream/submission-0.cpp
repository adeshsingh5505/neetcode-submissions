class KthLargest {
private:
    int l;
    priority_queue<int>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i:nums){
            pq.push(i);
        }
        l=k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> v;
        for(int i=1;i<l;i++){
            v.push(pq.top());
            pq.pop();
        }
        int ans=pq.top();
        while(!v.empty()){
            pq.push(v.top());
            v.pop();
        }
        return ans;
    }
};
