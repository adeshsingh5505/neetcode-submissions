class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n = senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int rr = r.front();r.pop();
            int dd = d.front();d.pop();
            if(rr<dd){
                r.push(rr+n);
            } else{
                d.push(dd+n);
            }
        }
        if(r.empty()) return "Dire";
        else return "Radiant";
    }
};