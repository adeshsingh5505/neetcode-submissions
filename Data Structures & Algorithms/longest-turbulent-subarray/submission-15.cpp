class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        int l=0,r=1,maxi=1;
        int flag=0;
        //1->inc,2->dec,0->none
        while(r<arr.size()){
            if(arr[r-1]>arr[r] && flag!=2){
                maxi=max(maxi,r-l+1);
                flag=2;
            } else if(arr[r-1]<arr[r]&&flag!=1){
                maxi=max(maxi,r-l+1);
                flag=1;
            } else {
                if(arr[r-1]==arr[r]){
                    l=r;
                    flag=0;
                }
                else{ 
                l=r-1;
                if(arr[r-1]<arr[r]) flag=1;
                else flag=2;
                }
            }
            r++;
        }
        return maxi;
    }
};