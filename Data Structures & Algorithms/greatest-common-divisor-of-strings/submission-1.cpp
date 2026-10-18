class Solution {
private:
    bool check(string s1, string s2, string res){
        string temp1="";
        while(temp1.size()<s1.size()){
            temp1+=res;
        }
        string temp2="";
        while(temp2.size()<s2.size()){
            temp2+=res;
        }
        //cout<<"temp1:"<<temp1<<" "<<"temp2:"<<temp2<<endl;
        return (temp1==s1) && (temp2==s2);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string res="";
        priority_queue<string> pq;
        pq.push("");
        for(auto i: str1){
            res+=i;
            //cout<<res<<" "<<check(str1,str2,res)<<endl;
            if(check(str1,str2,res)) pq.push(res);
        }
        return pq.top();
    }
};