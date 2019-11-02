//1237. Find Positive Integer Solution for a Given Equation
//https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x = 1, y = 1000;
        vector<vector<int>> res;
        while (x < 1001 && y > 0) {
            if (customfunction.f(x,y)==z) {
                vector<int> temp;
                temp.push_back(x);temp.push_back(y);
                res.push_back(temp);
                ++x; 
            }
            else if (customfunction.f(x,y)<z) ++x;
            else --y;
        }
        return res;
    }
};
