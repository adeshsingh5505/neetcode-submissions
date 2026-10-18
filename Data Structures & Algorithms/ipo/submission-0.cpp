class Solution {
public: 
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<profits.size();i++){
            pq.push({capital[i],profits[i]});
        }
        while(k--){
            priority_queue<pair<int,int>> pq1,pq2;
            while(!pq.empty()){
                pair<int,int> top = pq.top();
                pq.pop();
                if(top.first<=w){
                    pq2.push({top.second,top.first});
                } else{
                    pq1.push(top);
                }
            }
            if (pq2.empty()) break;
            w+=pq2.top().first;
            pq2.pop();

            while(!pq2.empty()){
                pq.push({pq2.top().second,pq2.top().first});
                pq2.pop();
            }
            while(!pq1.empty()){
                pq.push(pq1.top());
                pq1.pop();
            }
        }
        return w;
    }
};