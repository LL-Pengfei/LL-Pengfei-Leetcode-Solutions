//728. Self Dividing Numbers
//https://leetcode.com/problems/self-dividing-numbers/

class Solution {
public:
    bool is_sdn(int k) {
        int k_temp = k, divider;
        while (k_temp) {
            int divider = k_temp % 10;
            if (!divider) return false;
            if (k % divider != 0) return false;
            k_temp /= 10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) if (is_sdn(i)) res.push_back(i);
        return res;
    }
};
