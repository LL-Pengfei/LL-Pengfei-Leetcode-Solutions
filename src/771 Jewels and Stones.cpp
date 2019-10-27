//771. Jewels and Stones
//https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        const char* jc = J.c_str();
        const char* sc = S.c_str();
        unordered_set<char> jewel;
        for (int i = 0; i < J.size(); ++i) {
            jewel.insert(jc[i]);
        }
        int count = 0;
        for (int j = 0; j < S.size(); ++j) {
            if (jewel.find(sc[j]) != jewel.end()) ++count;
        }
        return count;
    }
};
