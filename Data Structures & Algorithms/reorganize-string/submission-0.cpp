class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto& i: s){
            mp[i]++;
        }

        int n = s.size();
        for(auto &i : mp){
            if(i.second > (n+1)/2) return "";
        }

        priority_queue<pair<int,char>> pq;
        for(auto& i: mp){
            pq.push({i.second,i.first});
        }

        string res(s.size(),'0');

        while(!pq.empty()){
            char ch=pq.top().second;
            int freq=pq.top().first;
            pq.pop();

            for(int i=0; i<s.size() && freq; i+=2){
                if(res[i]=='0'){
                    res[i]=ch;
                    freq--;
                }
            }
            for(int i=1; i<s.size() && freq; i+=2){
                if(res[i]=='0'){
                    res[i]=ch;
                    freq--;
                }
            }
        }
        return res;
    }
};
