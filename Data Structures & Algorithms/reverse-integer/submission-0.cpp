class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());

        long reversed = stol(s);
        if (x < 0) reversed *= -1;

        if (reversed < INT_MIN || reversed > INT_MAX)
            return 0;

        return (int)reversed;
    }
};
