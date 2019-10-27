//1025. Divisor Game
//https://leetcode.com/problems/divisor-game/ 

class Solution {
public:
    bool divisorGame(int N) {
        return (!(N%2)); //works cus for each k where one party loses, k+1 can win (choose 1 and make the other party lose)
    }
};



class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+5]; memset(dp, false, sizeof(dp));
        for (int i=2; i<=N; ++i)
            for (int j=1; j<i; ++j)
                if (!(i%j) && !(dp[i-j])) {
                    dp[i]=true; break;
                }
        return dp[N];
    }
};
