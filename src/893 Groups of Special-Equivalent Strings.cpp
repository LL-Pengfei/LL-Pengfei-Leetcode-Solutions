//893. Groups of Special-Equivalent Strings
//https://leetcode.com/problems/groups-of-special-equivalent-strings/

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        //common trick, sort to eliminate permutations
        unordered_set<string> f;
        for (auto &k : A) {
            string s1 = "", s2 = ""; int len = k.size();
            for (int i = 0; i < len; ++i) {
                if (i%2) s1 += k[i]; else s2 += k[i];
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            f.insert(s1+s2);
            //by right, should make f storing pair<string, string>, but in this case also can directly concat 2 strings into 1 (shave off some runtime)
        }
        return f.size();
    }
};
