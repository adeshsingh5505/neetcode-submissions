class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int> vv;
        for(set<int>::iterator it=s.begin(); it!=s.end();++it){
            vv.push_back(*it);
        }
        int maxi=-1;
        for(int i: vv) cout<<i<<" ";
        cout<<endl;
        vector<int> diff;
        for(int i=1;i<vv.size();i++){
            diff.push_back(vv[i]-vv[i-1]);
        }
        for(int i:diff)cout<<i<<" ";
        cout<<endl;
        int cnt=0;
        for(int i=0;i<diff.size();i++){
            if(diff[i]==1)cnt++;
            if(diff[i]!=1){
                maxi=max(maxi,cnt);
                cnt=0;
            }
        }
        maxi=max(maxi,cnt);
        return maxi+1;
    }
};
