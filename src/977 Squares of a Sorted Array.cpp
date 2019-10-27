//977. Squares of a Sorted Array
//https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        //merge idea
        int size = A.size(), itf = 0, ite = size-1; vector<int> res(size);
        while (size--) res[size] = (fabs(A[itf])>fabs(A[ite]))? (A[itf]*A[itf++]) : (A[ite]*A[ite--]);
        return res;
    }
};
