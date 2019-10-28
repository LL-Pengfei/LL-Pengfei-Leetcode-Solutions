//922. Sort Array By Parity II
//https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, size = A.size();
        for (int j = 1; j < size; j+=2) {
            while (i<size && !(A[i]%2)) i += 2; //make sure A[i] odd
            if (i<size && !(A[j]%2)) swap(A[i], A[j]);
        }
        return A;
    }
};
