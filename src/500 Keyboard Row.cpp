//500. Keyboard Row
//https://leetcode.com/problems/keyboard-row/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> s2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> s3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> res;
        for (auto &k : words) {
            string t = k;
            bool f1 = true, f2 = true, f3 = true;
            for (auto &c : k) {
                if (c>='A' && c<='Z') c = c-'A'+'a';
                if (s1.find(c)==s1.end()) f1 = false;
                if (s2.find(c)==s2.end()) f2 = false;
                if (s3.find(c)==s3.end()) f3 = false;
            }
            if (f1||f2||f3) res.push_back(t);
        }
        return res;
    }
};

/*
interesting solution on leetCode:
C++ solution use bit manipulations
Hcisly - Last Edit: October 8, 2018 11:34 AM
The idea is simple. Define a mask flag for each row. In my implementation, 
I define the flag for Row 1 ("QWERTYUIOP") as 1 (001), Row 2 ("ASDFGHJKL") as 2 (010), 
Row 3 ("ZXCVBNM") as 4 (100).
For each word, us 7 (111) as base, do AND operation on each character. If all chars 
from same row, the final result will be one of (1, 2, 4). If any character from other 
row, the final result will be 0.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) dict[c-'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words) {
            int r = 7;
            for (char c : w) {
                r &= dict[toupper(c)-'A'];
                if (r == 0) break;
            }
            if (r) res.push_back(w);
        }
        return res;
    }
};
*/
