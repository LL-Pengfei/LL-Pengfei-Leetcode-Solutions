//1002. Find Common Characters
//https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int size = A.size(), B[30] = {0}, C[30];
        for (auto &k : A[0]) ++B[k-'a'];
        for (int k = 1; k < size; ++k) {
            for (int j = 0; j < 30; ++j) C[j] = 0;
            for (auto &j : A[k]) ++C[j-'a'];
            for (int j = 0; j < 30; ++j) B[j]=min(B[j],C[j]);
        }
        vector<string> res;
        for (int k = 0; k < 30; ++k) {
            while (B[k] > 0) {
                --B[k];
                res.push_back(string(1, 'a'+k));
            }
        }
        return res;
    }
};

/* wrongly interpreted the question
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> f; int size = A.size();
        for (int k = 0; k < size; ++k) {
            string str = A[k];
            for (auto &j : str) {
                if (!k) {
                    ++f[j];
                } else {
                    if (f.find(j)!=f.end()) {
                        ++f[j];
                    }
                }
            }
        }
        vector<string> res;
        for (auto &k : f) {
            int num = k.second - 2;
            while (num > 0) {
                --num;
                res.push_back(string(1, k.first));
            }
        }
        return res;
    }
};
*/
