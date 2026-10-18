class Solution {
private:
    bool funct(int s, int n,vector<int> gas, vector<int> cost){
        int inf=0;
        for(int i=s;i<n;i++){
            inf+=gas[i];
            inf-=cost[i];
            if(inf<0)return 0;
        }
        for(int i=0;i<s;i++){
            inf+=gas[i];
            inf-=cost[i];
            if(inf<0)return 0;
        }
        return 1;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if(funct(i,n,gas,cost)) return i;
        }
        return -1;
    }
};
