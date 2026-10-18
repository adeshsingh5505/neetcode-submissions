#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;  // fixed: map instead of unordered_map

        for (string& s : strs) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }
            mp[freq].push_back(s);  // group anagrams with same char frequency
        }

        vector<vector<string>> ans;
        for (auto& [key, val] : mp) {
            ans.push_back(val);
        }

        return ans;
    }
};
