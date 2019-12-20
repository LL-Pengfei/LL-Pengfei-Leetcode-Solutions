//136. Single Number
//https://leetcode.com/problems/single-number/

//bit operation, fascinating approach to deal with
//linear runtime complexity + no extra memory
//Runtime: 12 ms, faster than 95.72% of C++ online submissions for Single Number.
//Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Single Number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto &k : nums) res ^= k;
        return res;
    }
};
