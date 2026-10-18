class Solution {
private:
    int solve(string word1, string word2, int n, int m, int idx1, int idx2){
        //insert all remaining
        if(idx1==word1.size()) return word2.size()-idx2;
        //delete all remaining
        if(idx2==word2.size()) return word1.size()-idx1;

        //if same no changes required ++
        if(word1[idx1]==word2[idx2]){
            return solve(word1,word2,n,m,idx1+1,idx2+1);
        }
        //delete
        int d=1+solve(word1,word2,n,m,idx1+1,idx2);
        //replace
        int r=1+solve(word1,word2,n,m,idx1+1,idx2+1);
        //insert
        int i=1+solve(word1,word2,n,m,idx1,idx2+1);

        return min({d,r,i});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return solve(word1,word2,n,m,0,0);
    }
};
