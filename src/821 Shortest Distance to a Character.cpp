//821. Shortest Distance to a Character
//https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
        vector<int> A; A.assign(len, INT_MAX);
        for (int i=0; i<len; ++i) {
            if (S[i] == C) {
                A[i] = 0;
                for (int j=i-1; j>=0; --j) {
                    if (i-j < A[j]) A[j]=i-j; else break;
                }
                for (int j=i+1; j<len; ++j) {
                    if (j-i < A[j]) A[j]=j-i; else break;
                }
            }
        }
        return A;
    }
};


/*
Alternative Interesting Solution:
vector<int> shortestToChar(string S, char C) {
    int len = S.length(), loc = -1;
    vector<int> result(len, INT_MAX);
    
    for(int i = 0; i < len; i++) {
        if(S[i] == C) loc = i;
        result[i] = min(result[i], loc != -1 ? abs(i - loc) : INT_MAX);
    }
    
    for(int i = len - 1; i >= 0; i--) {
        if(S[i] == C) loc = i;
        result[i] = min(result[i], abs(i - loc));
    }
    
    return result;
} 
*/
