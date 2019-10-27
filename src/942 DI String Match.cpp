//942. DI String Match
//https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int size = S.size(), l = 0, h = 0, i; vector<int> res(size+1); res[0] = 0;
        for (i = 1; i<=size; ++i) if (S[i-1] == 'I') res[i] = ++h; else res[i] = --l;
        for (i = 0; i <= size; ++i) res[i] -= l;
        return res;
    }
};
