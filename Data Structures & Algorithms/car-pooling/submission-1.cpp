class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        for(const auto& i: trips){
            int start=i[1],end=i[2],passenger=i[0];
            for(int j=start;j<end;j++){
                v[j]+=passenger;
                if(v[j]>capacity) return 0;
            }
        }
        return 1;
    }   
};