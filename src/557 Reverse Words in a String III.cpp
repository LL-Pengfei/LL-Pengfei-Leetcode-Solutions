//557. Reverse Words in a String III
//https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s); string temp; vector<string> res; string res_s;
        while (iss >> temp) res.push_back(temp);
        int len = res.size();
        for (int i = 0; i < len; ++i) {
            reverse(res[i].begin(), res[i].end());
            res_s = res_s + res[i];
            if (i != len-1) res_s = res_s + " ";
        }
        return res_s;
    }
};
