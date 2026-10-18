class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int len=0,idx=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2||dp[i+1][j-1])){
                    dp[i][j]=1;
                    if(len<(j-i+1)){
                        len=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return s.substr(idx,len);
    }
};
