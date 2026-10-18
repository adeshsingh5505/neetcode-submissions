class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int n=height.size();
        for(int i:height) sum+=i;
        int maxip=0,maxis=0;
        vector<int> pre,suf;
        for(int i=0;i<n;i++){
           pre.push_back(maxip);
           maxip=max(maxip,height[i]);
        }
        for(int i=n-1;i>=0;i--){
           suf.push_back(maxis);
           maxis=max(maxis,height[i]);
        }
        reverse(suf.begin(),suf.end());
        int ans=0;
        for(int i: pre) cout<<i<<" ";
        cout<<endl;
        for(int i:suf) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            if((min(pre[i],suf[i])-height[i])>0){
                ans+=min(pre[i],suf[i])-height[i];
            }
        }
        return ans;
    }
};
