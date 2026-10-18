class Solution {
private:
    bool isP(const string& st, int s, int e){
        while(s <= e){
            if(st[s] != st[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    void solve(const string& s, priority_queue<pair<int, string>>& pq){
        int n = s.size();
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(isP(s, i, j)){
                    pq.push({j - i + 1, s.substr(i, j - i + 1)});
                }
            }
        }
    }

public:
    string longestPalindrome(string s) {
        priority_queue<pair<int, string>> pq;
        solve(s, pq);
        return pq.top().second;
    }
};
