class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int rs = 0, cs = 0, re = n - 1, ce = m - 1;

        while(rs <= re && cs <= ce){
            // go right
            int r = cs;
            while(r <= ce){
                ans.push_back(matrix[rs][r]);
                r++;
            }
            rs++;

            // go down
            if (rs <= re) {
                int d = rs;
                while(d <= re){
                    ans.push_back(matrix[d][ce]);
                    d++;
                }
                ce--;
            }

            // go left
            if (rs <= re) {
                int l = ce;
                while(l >= cs){
                    ans.push_back(matrix[re][l]);
                    l--;
                }
                re--;
            }

            // go up
            if (cs <= ce) {
                int u = re;
                while(u >= rs){
                    ans.push_back(matrix[u][cs]);
                    u--;
                }
                cs++;
            }
        }

        return ans;
    }
};
