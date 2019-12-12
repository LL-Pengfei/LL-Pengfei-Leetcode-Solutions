//908. Smallest Range I
//https://leetcode.com/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int ma = -1e9, mi=1e9;
        for (auto &i : A) {
            if (i > ma) ma = i;
            if (i < mi) mi = i;
        }
        return max(0, ma-mi-2*K);
    }
};
