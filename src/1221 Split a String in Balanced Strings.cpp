//1221. Split a String in Balanced Strings
//https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0, res=0;
        for (auto &c : s)
          {if (c=='R') ++count; else --count; if (!count) ++res;}
        return res;
    }
};
