//1207. Unique Number of Occurrences
//https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //hash twice
        unordered_map<int, int> occur;
        unordered_map<int, int> num_occur;
        
        for (auto &i : arr) ++occur[i];
        for (auto &i : occur) {
            ++num_occur[i.second];
            if (num_occur[i.second] > 1) return false;
        }
        return true;
    }
}; 
