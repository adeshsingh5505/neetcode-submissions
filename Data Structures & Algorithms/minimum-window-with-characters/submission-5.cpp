class Solution {
private:
    bool check(vector<int> v1, vector<int> v2){
        for(int i=0;i<128;i++){
            if(v1[i]>v2[i]) return 0;
        }
        return 1;
    }
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0);
        vector<int> dhash(128, 0);

        for (char c : t) hash[c]++;

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            fill(dhash.begin(), dhash.end(), 0);

            for (int j = i; j < s.size(); j++) {
                if (hash[s[j]] != 0) {
                    dhash[s[j]]++;
                }

                if (check(hash,dhash)) {
                    string candidate = s.substr(i, j - i + 1);
                    if (ans.empty() || candidate.size() < ans.size()) {
                        ans = candidate;
                    }
                }
            }
        }

        return ans;
    }
};
