class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        if(triplets[0]==target) return 1;
        // int sum=target[0]+target[1]+target[2];
        // for(int i=0;i<triplets.size();i++){
        //     if(triplets[i][0]+triplets[i][1]+triplets[i][2]>sum){
        //         triplets.erase(triplets.begin()+i);
        //     }
        // }
        bool f1=0,f2=0,f3=0;
        for(int i=0;i<triplets.size();i++){
            for(int j=i+1;j<triplets.size();j++){
                if(max(triplets[i][0],triplets[j][0])==target[0]) f1=1;
                if(max(triplets[i][1],triplets[j][1])==target[1]) f2=1;
                if(max(triplets[i][2],triplets[j][2])==target[2]) f3=1;
            }
        }
        if(f1&&f2&&f3) return 1;
        return 0;
    }
};