class Solution {
public:
//TC=O(n^2) SC=O(n)
    int largestRectangleArea(vector<int>& heights) {
        priority_queue<int> pq;
        int n=heights.size();
        for(int i=0;i<n;i++){
            //go right
            int maxR=heights[i];
            for(int r=i+1;r<n;r++){
                if(heights[r]<heights[i]) break;
                maxR+=heights[i];
            }
            //go left
            int maxL=0;
            for(int l=i-1;l>=0;l--){
                if(heights[l]<heights[i]) break;
                maxL+=heights[i];
            }
            pq.push(maxL+maxR);
            cout<<maxR<<" "<<maxL<<endl;
        }
        return pq.top();
    }
};
