//832. Flipping an Image
//https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &i : A)
            for (auto &j : i)
                if (j == 0) j = 1; else j = 0;
        
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A.size()/2; ++j)
                swap(A[i][j], A[i][A.size()-1-j]);
        
        return A;
    }
};


