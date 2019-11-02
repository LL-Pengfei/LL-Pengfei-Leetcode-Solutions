//1200. Minimum Absolute Difference
//https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX, size = arr.size();
        vector<vector<int>> res;
        for (int i = 0; i < size-1; ++i) {
            if (fabs(arr[i]-arr[i+1]) < diff) {
                diff = fabs(arr[i]-arr[i+1]);
                res.clear();
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                res.push_back(temp);
            } else if (fabs(arr[i]-arr[i+1]) == diff) {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
