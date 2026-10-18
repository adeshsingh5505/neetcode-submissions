class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        int sr=0,en=n-1;
        vector<int> start(26,-1),end(26,-1);
        while(sr<n && en>=0){
            if(start[s[sr]-'a']==-1) start[s[sr]-'a']=sr;
            if(end[s[en]-'a']==-1) end[s[en]-'a']=en;
            sr++;en--;
        }
        vector<pair<int,int>> merge;
        for(int i=0;i<26;i++){
            if(start[i]!=-1)merge.push_back({start[i],end[i]});
        }
        sort(merge.begin(),merge.end());
        for(auto i:merge)cout<<i.first<<" "<<i.second<<endl;
        for(int i=0;i<merge.size()-1;i++){
            if(merge[i].second>=merge[i+1].first){
                merge[i].second=max(merge[i+1].second,merge[i].second);
                merge.erase(merge.begin()+i+1);
                i--;
            }
        }
        vector<int> ans;
        for(auto i:merge)cout<<i.first<<" "<<i.second<<endl;
        for(auto i:merge)ans.push_back(i.second-i.first+1);

        return ans;
    }
};
