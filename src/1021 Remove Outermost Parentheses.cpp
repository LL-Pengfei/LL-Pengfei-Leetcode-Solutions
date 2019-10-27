//1021. Remove Outermost Parentheses
//https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "", temp_stack = "";
        for (int i = 0; i < S.size(); ++i)
            if (S[i] == '(') {
                if (temp_stack != "") res += '(';
                temp_stack.push_back('('); 
            } else {
                temp_stack.pop_back();
                if (temp_stack != "") res += ')';
            }
        return res;
    }
};
