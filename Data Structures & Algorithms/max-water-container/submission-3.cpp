class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxi = -1;
        int n = heights.size();
        int i = 0, j = n - 1;
        while (i < n && j < n) {
            int vol = (j - i) * min(heights[i], heights[j]);
            maxi = max(maxi, vol);
            if (heights[i] > heights[j])
                j--;
            else
                i++;
        }
        return maxi;
    }
};
