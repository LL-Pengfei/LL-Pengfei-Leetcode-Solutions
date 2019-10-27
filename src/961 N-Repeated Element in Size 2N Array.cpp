//961. N-Repeated Element in Size 2N Array
//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> f;
        for (auto &i : A) {
            ++f[i];
            if (f[i] > 1) return i;
        }
        return 0;
    }
};
