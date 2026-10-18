class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> heap;

        if(a>0) heap.push({a,'a'});
        if(b>0) heap.push({b,'b'});
        if(c>0) heap.push({c,'c'});

        string ans="";

        while(!heap.empty()){
            if(ans.size()>1 && ans[ans.size()-1]==ans[ans.size()-2] && 
            ans[ans.size()-2]==heap.top().second){
                if(heap.empty()) break;
                auto temp=heap.top();
                heap.pop();

                if(heap.empty()) break;

                auto temp2=heap.top();
                heap.pop();
                ans+=temp2.second;
                temp2.first--;
                heap.push(temp);

                if(temp2.first>0)heap.push(temp2);

            }else{
                auto temp=heap.top();
                heap.pop();
                ans+=temp.second;
                temp.first--;
                if(temp.first>0) heap.push(temp);
            }
        }
        return ans;
    }
};