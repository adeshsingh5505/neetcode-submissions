class Solution {
private:
    int solve(string word1, string word2, int n, int m, int idx1, int idx2,vector<vector<int>> &dp){
        //insert all remaining
        if(idx1==word1.size()) return word2.size()-idx2;
        //delete all remaining
        if(idx2==word2.size()) return word1.size()-idx1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        //if same no changes required ++
        if(word1[idx1]==word2[idx2]){
            return dp[idx1][idx2]=solve(word1,word2,n,m,idx1+1,idx2+1,dp);
        }
        //delete
        int d=1+solve(word1,word2,n,m,idx1+1,idx2,dp);
        //replace
        int r=1+solve(word1,word2,n,m,idx1+1,idx2+1,dp);
        //insert
        int i=1+solve(word1,word2,n,m,idx1,idx2+1,dp);

        return dp[idx1][idx2]=min({d,r,i});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,n,m,0,0,dp);
    }
};
