class Solution {
private:
    bool solve(vector<int> &nums, vector<int> &visited, int curr,int idx, int sum,int k){
        if(k==1) return 1;
        if(curr==sum) return solve(nums,visited,0,0,sum,k-1);
        for(int i=idx;i<nums.size();i++){
            if(!visited[i] && curr+nums[i]<=sum){
                visited[i]=1;
                if(solve(nums,visited,curr+nums[i],i+1,sum,k)) return 1;
                visited[i]=0;
            }
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0) return 0;
        int chunk = total/k;
        int n = nums.size();
        vector<int> visited(n,0);
        int cnt = 0;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > chunk) return false;
        return solve(nums,visited,0,0,chunk,k);
    }
};