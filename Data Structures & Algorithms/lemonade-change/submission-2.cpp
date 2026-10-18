class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,tt=0;
        for(auto& i: bills){
            if(i==5){
                f++;
                continue;
            }
            if(i==10){
                if(f==0) return 0;
                t++;
                f--;
            }
            if(i==20){
                if(f>0 && t>0){
                    f--;
                    t--;
                    tt++;
                    continue;
                } else if(f>=3){
                    f-=3;
                    tt++;
                    continue;
                } else{
                    return 0;
                }
            }
        }
        return 1;
    }
};