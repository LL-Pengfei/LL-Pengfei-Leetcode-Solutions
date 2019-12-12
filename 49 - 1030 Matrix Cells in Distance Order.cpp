//1030. Matrix Cells in Distance Order
//https://leetcode.com/problems/matrix-cells-in-distance-order/

//multimap solution
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        multimap<int, vector<int>> f; vector<vector<int>> res;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int dist = fabs(i-r0) + fabs(j-c0);
                f.insert({dist,{i, j}});
            }
        }
        for (auto &k : f) {
            res.push_back(k.second);
        }
        return res;
    }
};

//minheap solution
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        /*
        minheap std: priority_queue<int, std::vector<int>, std::greater<int> > q2;
        
        auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
        */
        vector<vector<int>> res; vector<int> temp;
        auto cmp = [r0, c0](vector<int> &a, vector<int> &b) {return ((abs(a[0]-r0)+abs(a[1]-c0))>(abs(b[0]-r0)+abs(b[1]-c0)));};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                q.push({i, j});
            }
        }
        
        while (!q.empty()) {
            temp = q.top(); q.pop();
            res.push_back(temp);
        }
        return res;
    }
};


