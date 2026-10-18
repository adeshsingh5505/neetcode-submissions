class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=numbers.size()-1;
        vector<int> ans;
        while(ans.empty()&&i<n&&j<n){
            if(numbers[i]+numbers[j]==target) ans={i+1,j+1};
            if(numbers[i]+numbers[j]<target) i++;
            if(numbers[i]+numbers[j]>target) j--;
        }
        return ans;
    }
};
