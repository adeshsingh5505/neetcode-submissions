class Solution {
private:
    double dist(int x, int y){
        double ans = sqrt(x * x + y * y);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        int n=points.size();
        int j=0;
        while(j<n){
            pq.push({dist(points[j][0],points[j][1]),j});
            j++;
        }
        vector<vector<int>> ans;
        // while(!pq.empty()){
        //     cout<<pq.top().second<<" ";
        //     pq.pop();
        // }
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
