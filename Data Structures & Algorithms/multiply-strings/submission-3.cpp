class Solution {
public:
    string multiply(string num1, string num2) {
        return to_string(stol(num1)*stol(num2));
    }
};
