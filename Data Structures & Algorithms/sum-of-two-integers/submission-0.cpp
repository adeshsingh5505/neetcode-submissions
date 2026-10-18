class Solution {
public:
    int getSum(int a, int b) {
        //XOR fives sum without carry AND gives carry
        while(b!=0){
            int carry=(b&a)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};
