//476. Number Complement
//https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        long long k = 1, i = 2, num_ll = (long long)num;
        while (k<num_ll) {
            i*=2; k=i-1;
        }
        return (int)k-num_ll;
    }
};

/*
interesting solutions on leetcode discussion:
///////////////////////////////////////////////////////////
// OJ: https://leetcode.com/problems/number-complement/
// Author: github.com/lzl124631x
// Time: O(1) as there are at most 32 bits to move
// Space: O(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};

For example,

num          = 00000101
mask         = 11111000
~mask & ~num = 00000010
More codes at my github repo LeetCode https://github.com/lzl124631x/LeetCode
///////////////////////////////////////////////////////////
3 line pure C
int findComplement(long num) {
    long i;
    for(i=1;i<=num;i*=2) num^=i; 
    return num;
}
I basically check every bit of number by XOR'ing it with appropriate power of 2 which leads to its invertion.
For example:
Entered: 4=>100;
100 ^ 001 = 101;
101 ^ 010 = 111;
111 ^ 100 = 011;
Out:     011=>3;
////////////////////////////////////////////////////////////
Java, very simple code and self-evident, explanation
for example:
100110, its complement is 011001, the sum is 111111. So we only need get the min number large or equal to num, then do substraction
 public int findComplement(int num) 
    {
        int i = 0;
        int j = 0;
        
        while (i < num)
        {
            i += Math.pow(2, j);
            j++;
        }
        
        return i - num;
    }
///////////////////////////////////////////////////////////
maybe fewest operations
Spread the highest 1-bit onto all the lower bits. Then xor with that.
int findComplement(int num) {
    int mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    return num ^ mask;
}
When you lookup highestOneBit source code in Integer.java, you will find same method.

personal comment: essentially creating a mask here, a mask of 111...11111 that fits the total digit
10000000
11000000
11110000
11111111
note the use of or rather than xor here
*/
