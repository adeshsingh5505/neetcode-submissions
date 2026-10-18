class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        for(const auto& i: operations){
            if(i=="+"){
                int sum=0;
                stack<int> temp=st;
                for(int i=0;i<2;i++){
                    sum+=temp.top();
                    temp.pop();
                }
                st.push(sum);
            }
            else if(i=="C"){
                st.pop();
            }
            else if(i=="D"){
                int t=st.top();
                //st.pop();
                st.push(2*t);
            }
            else{
                st.push(stoi(i));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};