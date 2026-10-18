class FreqStack {
priority_queue<vector<int>> pq;
//freq,idx,val
unordered_map<int,int> mpF;
int idx=0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        mpF[val]++;
        pq.push({mpF[val],idx++,val});
    }
    
    int pop() {
        auto it=pq.top();
        pq.pop();
        int val=it[2];
        mpF[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */