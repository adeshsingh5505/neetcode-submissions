class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(b.size()<a.size()){
            b+='0';
        } 
        while(a.size()<b.size()){
            a+='0';
        }    
        bool flag=0;
        string res="";
        for(int i=0;i<a.size();i++){
            if(a[i]=='1' && b[i]=='1' && !flag){
                res+='0';
                flag=1;
            } else if(a[i]=='1' && b[i]=='0' && flag|| a[i]=='0' && b[i]=='1' && flag){
                res+='0';
            } else if(a[i]=='1' && b[i]=='0' && !flag|| a[i]=='0' && b[i]=='1' && !flag){
                res+='1';
            } else if(a[i]=='0' && b[i]=='0' && flag){
                res+='1';
                flag=0;
            } else if(a[i]=='0' && b[i]=='0' && !flag){
                res+='0';
            } else if(a[i]=='1' && b[i]=='1' && flag){
                res+='1';
            }
        }
        if(flag) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};