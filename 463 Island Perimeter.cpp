//463. Island Perimeter
//https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]==1) {
                    if (i==0 || grid[i-1][j]==0) ++res;
                    if (i==r-1 || grid[i+1][j]==0) ++res;
                    if (j==0 || grid[i][j-1]==0) ++res;
                    if (j==c-1 || grid[i][j+1]==0) ++res;
                }
            }
        }
        return res;        
    }
};
