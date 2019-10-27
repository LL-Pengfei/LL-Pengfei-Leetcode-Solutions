//657. Robot Return to Origin
//https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int dr[] = {0, 0, 1,-1}; int dc[] = {1,-1, 0, 0};
        int cr = 0, cc = 0; //curr row & col
        for (auto &i : moves) {
            if (i == 'R') {
                cr += dr[0]; cc += dc[0];
            } else if (i == 'L') {
                cr += dr[1]; cc += dc[1];
            } else if (i == 'U') {
                cr += dr[2]; cc += dc[3];
            } else {
                cr += dr[3]; cc += dc[3];
            } 
        }
        if (cr == 0 && cc == 0) return true; else return false;
    }
};
