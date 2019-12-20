//1046. Last Stone Weight
//https://leetcode.com/problems/last-stone-weight/

//standard heap question
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &k : stones) pq.push(k);
        while (pq.size()>1) {
            int a1 = pq.top(); pq.pop();
            int a2 = pq.top(); pq.pop();
            pq.push(a1-a2);
        }
        return pq.top();
    }
};
