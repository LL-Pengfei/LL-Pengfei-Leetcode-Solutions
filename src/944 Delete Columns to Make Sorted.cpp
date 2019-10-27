//944. Delete Columns to Make Sorted
//https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int row = A.size(), col = A[0].size(), i, j, res=0;
        for (i = 0; i < col; ++i) {
            bool flag = false;
            for (j = 1; j < row; ++j) if (A[j][i] < A[j-1][i]) {flag = true; break;}
            if (flag) ++res;
        }
        return res;
    }
};
