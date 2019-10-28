//905. Sort Array By Parity
//https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, k = A.size(); //take A[0] as the pivot
        for (int j = 1; j < k; ++j) if (A[j] % 2 == 0) swap(A[++i], A[j]);
        swap(A[0], A[i]);
        return A;
    }
};


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, k = A.size();
        for (int j = 0; j < k; ++j) if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};
