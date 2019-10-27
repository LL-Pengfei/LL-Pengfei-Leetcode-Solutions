//929. Unique Email Addresses
//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string, string>> res;
        for (auto &i : emails) {
            string local, domain, temp, local_reform="";
            istringstream iss1(i);
            getline(iss1, local, '@'); getline(iss1, domain, '@');
            istringstream iss2(local); getline(iss2, local, '+');
            istringstream iss3(local); vector<string> local_seg;
            while (getline(iss3, temp, '.'))
                local_seg.push_back(temp);
            for (auto &k : local_seg) local_reform += k;
            res.insert(make_pair(local_reform, domain));
        }
        return res.size();
    }
};
