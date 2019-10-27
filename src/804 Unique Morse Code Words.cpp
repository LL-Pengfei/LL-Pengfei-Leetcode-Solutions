//804. Unique Morse Code Words
//https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mapping[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
                         "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                         ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                         "-.--", "--.."};
        set<string> myset;
        for (auto &i : words) {
            string temp = "";
            for (auto &j : i) {
                temp += mapping[j - 'a'];
            }
            myset.insert(temp);
        }
        return myset.size();
    }
};
