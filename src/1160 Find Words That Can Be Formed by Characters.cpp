//1160. Find Words That Can Be Formed by Characters
//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> f, fdup; int res=0;
        for (auto &k : chars) ++f[k];
        for (auto &k : words) {
            int len = k.size(); fdup = f; bool flag = true;
            for (auto &m : k) {
                --fdup[m];
                if (fdup[m]<0) {flag = false; break;}
            }
            if (flag) res += len;
        }
        return res;
    }
};
