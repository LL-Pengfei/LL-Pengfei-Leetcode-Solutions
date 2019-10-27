//561. Array Partition I
//https://leetcode.com/problems/array-partition-i/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int size = nums.size(), i, res = 0;
        sort(nums.begin(), nums.end());
        for (i = 0; i < size/2; ++i) res += nums[2*i];
        return res;
    }
};
