class Solution {
    int bs(vector<int> nums, int target, int s, int e) {
        if (s > e) return -1;
        int mid = e + (s - e) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) s = mid + 1;
        else e = mid - 1;
        return bs(nums, target, s, e);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), e = matrix[0].size();
        vector<int> v0;
        for (int i = 0; i < n; i++) {
            v0.push_back(matrix[i][0]); // first column
        }

        int k = -1;
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (v0[m] == target) return true;
            if (v0[m] < target) {
                l = m + 1;
                k = m;
            } else {
                h = m - 1;
            }
        }

        if (k == -1) return false;
        int ll = bs(matrix[k], target, 0, e - 1);
        return ll != -1;
    }
};
