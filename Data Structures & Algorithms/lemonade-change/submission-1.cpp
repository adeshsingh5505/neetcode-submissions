class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0;
        for(auto& i: bills){
            if(i==5){
                f++;
            }
            else if(i==10){
                if(f==0) return 0;
                else{
                    f--;
                }
                t++;
            }
            else{
                if(f && t){
                    f--;
                    t--;
                } else if(f>=3){
                    f-=3;
                } else{
                    return 0;
                }
            }
        }
        return 1;
    }
};