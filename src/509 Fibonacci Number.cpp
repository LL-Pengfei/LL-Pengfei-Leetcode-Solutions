//509. Fibonacci Number
//https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        if (!N) return 0; else if (N==1) return 1;
        int a = 0, b = 1, c;
        while (--N) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
