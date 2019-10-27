//1108. Defanging an IP Address 
//https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        istringstream iss(address);
        int i = 0; string j, a[4], res = "";
        while (getline(iss, j, '.')) a[i++]=j;
        while (i--) res = res + a[3-i] + ((i != 0) ? "[.]" : "");
        return res;
    }
};
