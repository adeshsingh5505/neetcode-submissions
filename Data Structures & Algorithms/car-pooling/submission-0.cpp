class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int s=1e9,e=-1e9;
        for(auto i: trips){
            s=min(s,i[1]);
            e=max(e,i[2]);
        }
        vector<int> v(e,0);
        for(auto i: trips){
            int start=i[1],end=i[2],passenger=i[0];
            for(int j=start;j<end;j++){
                v[j]+=passenger;
            }
        }
        for (auto i:v){
            if(i>capacity) return 0;
        }
        return 1;
    }   
};