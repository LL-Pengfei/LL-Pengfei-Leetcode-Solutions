//1217. Play with Chips
//https://leetcode.com/problems/play-with-chips/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int a=0, b=0;
        for (auto &k : chips) {
            if (k%2) ++a; else ++b;
        }
        return min(a, b);
    }
};

//There are some chips, and the i-th chip is at position chips[i].
//meaning that the array element denotes the position of the particular chip, specified by the array index
/*
interesting solution on leetcode
 
int minCostToMoveChips(vector<int>& chips) {
  int cnt[2] = {};
  for (auto p : chips) ++cnt[p % 2];
  return min(cnt[0], cnt[1]);
}
*/
