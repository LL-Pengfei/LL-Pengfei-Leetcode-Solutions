//1051. Height Checker
//https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights2 = heights;
        sort(heights.begin(), heights.end());
        int res = 0, i = heights.size();
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != heights2[i]) ++res;
        }
        return res;
    }
};
