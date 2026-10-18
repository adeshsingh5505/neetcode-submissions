class Solution {
private:
    int bs(vector<int>& piles, int maxi, int h, int n){
        int left = 1, right = maxi;
        int ans = maxi;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long cnt = 0;

            for (int i = 0; i < n; i++) {
                cnt += (piles[i] + mid - 1) / mid; 
            }

            if (cnt > h) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }

        return ans;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        return bs(piles, maxi, h, piles.size());
    }
};
