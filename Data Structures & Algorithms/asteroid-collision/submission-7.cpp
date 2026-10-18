class Solution {
private:
    bool willCollide(int a, int b){
        if(a<0 && b>0 || a>0 && b>0 || a<0 && b<0) return 0;
        return 1;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int& a:asteroids){
            if(!st.empty()){
                //same size
                if(willCollide(st.top(),a) && st.top()==abs(a)){
                    st.pop();
                    continue;
                }
                //greater size
                if(willCollide(st.top(),a) && st.top()>abs(a)) continue;
                //lesser size
                while(willCollide(st.top(),a) && st.top()<abs(a)){
                    st.pop();
                    if(st.empty()) break;
                }
            }
            if(!st.empty() && willCollide(st.top(),a)){
                if(st.top()<abs(a)){
                    st.pop();
                    st.push(a);
                }
                if(st.top()==abs(a)) st.pop();
                continue;
            }
            st.push(a);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};