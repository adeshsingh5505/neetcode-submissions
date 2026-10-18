/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int findPeak(MountainArray &mountainArr){
        int s=0,e=mountainArr.length()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s=mid+1;
            } else e=mid;
        }
        return s;
    }
    int bs1(int target, MountainArray &mountainArr, int s, int e){
        while(s <= e){
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
    int bs2(int target, MountainArray &mountainArr, int s, int e){
        while(s <= e){
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val > target) s = mid + 1; 
            else e = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int curr=mountainArr.get(1);
        int prev=mountainArr.get(0);
        int n=mountainArr.length();
        int ans=findPeak(mountainArr);
        int left = bs1(target, mountainArr, 0, ans);
        if(left != -1) return left;

        return bs2(target, mountainArr, ans+1, n-1);
    }
};