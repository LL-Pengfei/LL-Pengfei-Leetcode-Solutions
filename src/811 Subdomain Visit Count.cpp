//811 Subdomain Visit Count
//https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> f;
        for (auto &k : cpdomains) {
            int num; string temp0; //parse into num & domain
            istringstream iss(k);
            iss >> num >> temp0;
            
            istringstream iss1(temp0); //parse domain
            vector<string> A; string temp1;
            while (getline(iss1, temp1, '.')) A.push_back(temp1);
            
            int len = A.size(); //can be 2 or 3 in this case
            for (int i = len-1; i >= 0; --i) { //more general
                f[A[i]] += num;
                if (i) A[i-1] = A[i-1]+'.'+A[i];
            }
        }
        
        vector<string> res;
        for (auto &k : f) {
            res.push_back(to_string(k.second)+' '+k.first);
        }
        return res;
    }
};
