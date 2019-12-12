//1047. Remove All Adjacent Duplicates In String 
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string S) {
        string res; stack<char> f;
        for (auto &k : S) {
            if (f.empty()) f.push(k);
            else {
                if (f.top() == k) {
                    f.pop();
                } else {
                    f.push(k);
                }
            }
        }
        while (!f.empty()) {
            char temp = f.top(); f.pop();
            res += temp;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
