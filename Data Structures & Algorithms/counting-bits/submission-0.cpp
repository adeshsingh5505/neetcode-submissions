class Solution {
private:
    int countOne(int k){
        int cnt=0;
        for(int i=0;i<32;i++){
            //(1<<i) shifts the pointer by 1 in bit represenation
            //1&1==1 1&0==0
            //k&(1<<i) checks ith bit of k
            if(k&(1<<i))cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countOne(i));
        }
        return ans;
    }
};
