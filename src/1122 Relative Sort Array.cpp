//1122. Relative Sort Array
//https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1010] = {0,}; vector<int> res;
        for (auto &k : arr1) ++count[k];
        for (auto &k : arr2) {
            int num = count[k]; count[k] = 0;
            while (num--) res.push_back(k);
        }
        for (int i = 0; i < 1010; ++i) {
            while (count[i]--) {
                res.push_back(i);
            }
        }
        return res;
    }
};
