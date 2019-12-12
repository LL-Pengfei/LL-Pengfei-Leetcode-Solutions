//806. Number of Lines To Write String
//https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int a = 1, b = 0, c; //S length guaranteed > 0, hence possible to do this, otherwise will have problem when S is empty string
        for (auto &k : S) {
            c = widths[k-'a']; b=b+c;
            if (b>100) {
                b = c; ++a; //write this on the new line
            }
        }
        return {a, b};
    }
};
