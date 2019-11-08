//1078. Occurrences After Bigram
//https://leetcode.com/problems/occurrences-after-bigram/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        vector<string> data, res;
        string temp;
        while (iss>>temp)
            data.push_back(temp);
        int len = data.size();
        for (int i = 0; i < len-2; ++i)
            if (data[i]==first && data[i+1]==second)
                res.push_back(data[i+2]);
        return res;
    }
};

/* Alternative Solution on Leetcode, using substr, find:
vector<string> findOcurrences(string raw_text, string first, string second) {
  vector<string> res;
  auto bigram = " " + first + " " + second + " ", text = " " + raw_text;
  auto p = text.find(bigram);
  while (p != string::npos) {
    auto p1 = p + bigram.size(), p2 = p1;
    while (p2 < text.size() && text[p2] != ' ') ++p2;
    res.push_back(text.substr(p1, p2 - p1));
    p = text.find(bigram, p + 1);
  }
  return res;
}
*/
