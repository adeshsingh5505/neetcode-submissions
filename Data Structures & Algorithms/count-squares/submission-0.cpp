class CountSquares {
    unordered_map<int,unordered_map<int,int>> hash;
public:
    CountSquares() {}
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        hash[x][y]++;
    }
    int count(vector<int> point) {
        int res=0;
        int qx=point[0],qy=point[1];
        for(auto &[y2, cnt]:hash[qx]){
            int side=y2-qy;
            if(side==0) continue;

            int x3=qx+side,x4=qx-side;
            res+=cnt*hash[x3][qy]*hash[x3][y2];
            res+=cnt*hash[x4][qy]*hash[x4][y2];
        }
        return res;
    }
};
