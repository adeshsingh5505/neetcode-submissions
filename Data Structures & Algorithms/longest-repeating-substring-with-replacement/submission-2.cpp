class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int i = 0, j = 0, maxFreq = 0, maxLen = 0;

        while (j < s.length()) {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            if ((j - i + 1) - maxFreq > k) {
                hash[s[i] - 'A']--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
