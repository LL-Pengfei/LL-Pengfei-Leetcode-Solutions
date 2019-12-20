//682. Baseball Game
//https://leetcode.com/problems/baseball-game/

//Runtime: 4 ms, faster than 96.63% of C++ online submissions for Baseball Game.
//Memory Usage: 9.5 MB, less than 75.00% of C++ online submissions for Baseball Game.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> res;
        for (auto &k : ops) {
            if (k == "+") {
                int a1 = res.top(); res.pop();
                int a2 = res.top();
                int a3 = a1 + a2;
                res.push(a1); res.push(a3);                
            } else if (k == "D") {
                int a1 = res.top();
                res.push(a1*2);
            } else if (k == "C") {
                res.pop();
            } else {
                int a1 = stoi(k);
                res.push(a1);
            }
        }
        int p = 0;
        while (!res.empty()) {
            p += res.top(); res.pop();
        }
        return p;
    }
};
