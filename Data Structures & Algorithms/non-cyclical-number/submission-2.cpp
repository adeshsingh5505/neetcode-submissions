class Solution {
private:
    void convrt(int n, int &x){
        if(n<=0) return;
        int digit=n%10;
        x+=(digit*digit);
        n=n/10;
        convrt(n,x);
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && !seen.count(n)){
            seen.insert(n);
            int x=0;
            convrt(n,x);
            n=x;
            
        }
        return n==1;
    }
};
