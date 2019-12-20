//985. Sum of Even Numbers After Queries
//https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res; int p = 0;
        for (auto &k : A) if (k%2==0) p+=k;
        for (auto &k : queries) {
            //k[0] == val; k[1] == index
            if (A[k[1]]%2==0) p -= A[k[1]];
            A[k[1]] += k[0];
            if (A[k[1]]%2==0) p+=A[k[1]];
            res.push_back(p);
        }
        return res;        
    }
};
