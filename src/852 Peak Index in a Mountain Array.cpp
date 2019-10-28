//852. Peak Index in a Mountain Array
//https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int size = A.size(), low = 0, high = size-1, mid;
        while (low<=high) {
            mid = (low+high)/2;
            if (A[mid]>A[mid-1] && A[mid]>A[mid+1]) break; else if (A[mid]<A[mid+1]) low = mid+1; else high = mid-1;
        }
        return mid;
    }
};
