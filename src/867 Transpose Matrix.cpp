//867. Transpose Matrix
//https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int R = A.size(), C = A[0].size();
        vector<vector<int>> res;
        res.assign(C, vector<int>()); for (auto &k : res) k.assign(R, 0);
        //newer mtd(C++14): vector<vector<int>> res(C, vector<int>(R, 0));
        
		for (int i = 0; i < R; ++i) {
            for (int j = 0; j <C; ++j) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
