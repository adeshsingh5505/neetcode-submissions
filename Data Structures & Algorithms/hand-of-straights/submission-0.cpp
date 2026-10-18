class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<int> hash(1001,0);
        sort(hand.begin(),hand.end());
        for(int i:hand) hash[i]++;
        for(int i:hand){
            if(hash[i]==0) continue;
            for(int j=i;j<i+groupSize;j++){
                if(hash[j]==0) return 0;
                hash[j]--;
            }
        }
        return 1;
    }
};
