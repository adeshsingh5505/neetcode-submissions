class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int maxi=-1e9;
        while(j<n && i<n){
            int vol=(j-i)*min(heights[i],heights[j]);
            maxi=max(maxi,vol);
            if(heights[i]<heights[j] ){
                i++;
            }
            else 
            j--;
        }
        cout<<i<<--j<<endl;
        return maxi;
    }
};
