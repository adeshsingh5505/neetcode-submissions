class Solution {
private:
    void merge(vector<int> &arr, int low, int mid, int high){
        int i=low,j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=high) temp.push_back(arr[j++]);
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high){
        if(low>=high) return;
        int mid=(high+low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};