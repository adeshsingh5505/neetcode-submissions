class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> pre, suff;
        int n = height.size();
        int maxpre = 0, maxsuff = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pre.push_back(maxpre);
            maxpre = max(maxpre, height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suff.push_back(maxsuff);
            maxsuff = max(maxsuff, height[i]);
        }
        reverse(suff.begin(), suff.end());
        for (int i = 0; i < n; i++) {
            if (min(suff[i], pre[i]) - height[i]>0) {
                ans += (min(suff[i], pre[i]) - height[i]);
            }
        }
        return ans;
    }
};
