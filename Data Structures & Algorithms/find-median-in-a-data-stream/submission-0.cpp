class MedianFinder {
vector<int> v;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        double ans;
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2==0){
            ans=double(v[n/2]+v[(n/2)-1])/2.0;
        }
        else{
            ans=double(v[n/2]);
        }
        return ans;
    }
};
