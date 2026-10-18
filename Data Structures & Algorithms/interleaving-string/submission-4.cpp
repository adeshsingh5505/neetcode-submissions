class Solution {
private:
    bool solve(string s1, string s2, string s3, int i, int j, int k,vector<vector<int>> &dp){
        if(k>=s3.size()) return 1;
        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool p=0,q=0,r=0;
        if(s1[i]==s3[k] && s2[j]==s3[k] && i+1<s1.size() && j+1 <s2.size()){
            p= solve(s1,s2,s3,i+1,j,k+1,dp)||solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        if(s1[i]==s3[k] && i+1<s1.size() || j>=s2.size()-1){
            q= solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s2[j]==s3[k] && j+1<s2.size() || i>=s1.size()-1){
            r= solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]=p||q||r;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return 0;
        if(s1+s2==s3 || s2+s1==s3) return 1;
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
