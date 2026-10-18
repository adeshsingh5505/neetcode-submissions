class Solution {
private:
    double solve(double x, int n){
        if(n==0) return 1;
        if(n%2==0){
            double temp=solve(x,n/2);
            return temp*temp;
        }
        else{
            double temp=solve(x,n/2);
            return x*temp*temp;
        }
    }
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) return 1/solve(x,n);
        return solve(x,n);
    }
};
