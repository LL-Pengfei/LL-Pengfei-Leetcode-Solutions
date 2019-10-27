//461. Hamming Distance
//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32>(x^y).count();
    }
};



class Solution {
public:
    int hammingDistance(int x, int y) {
        int A[40] = {0}, B[40] = {0}, i = 0, j = 0, count = 0;
        while (x) A[i++] = x % 2, x /= 2;
        while (y) B[j++] = y % 2, y /= 2;
        for (int k = 0; k < 40; ++k) if (A[k] != B[k]) ++count;
        return count;
    }
};
