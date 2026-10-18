class Solution {
private:
    int solve( int r, int c, int m, int n){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(r>=m || c>=n) return 0;
        int down=solve(r+1,c,m,n);
        int right=solve(r,c+1,m,n);
        return down+right;
    }
public:
    int uniquePaths(int m, int n) {
        //solve using DP
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n);
    }
};
