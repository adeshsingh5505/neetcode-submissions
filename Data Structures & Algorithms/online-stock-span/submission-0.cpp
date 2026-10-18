class StockSpanner {
stack<pair<int,int>> st;
public:
    StockSpanner() {}
    
    int next(int price) {
        int span=1;
        while(!st.empty()){
            if(price<st.top().first) break;
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */