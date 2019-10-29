//883. Projection Area of 3D Shapes
//https://leetcode.com/problems/projection-area-of-3d-shapes/
 
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0, size = grid[0].size();
        for (int i = 0; i < size; ++i) {
            int max1 = 0, max2 = 0;
            for (int j = 0; j < size; ++j) {
                if (grid[i][j]) ++res;
                if (grid[i][j] > max1) max1 = grid[i][j];
                if (grid[j][i] > max2) max2 = grid[j][i];
            }
            res += max1+max2;
        }
        return res;
    }
};
