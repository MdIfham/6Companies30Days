// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#define ll long long

class Solution {
    int myAtoi(string& s) {
        int res = 0, i = 0;
        int sign = 1;
        
        //ignore leading white space
        while (i < s.size() && s[i] == ' ') { i++; }
        //check if number positve or negative
        if (s[i] == '-' || s[i] == '+') {  sign = (s[i] == '-') ? -1 : 1; i++; }

        // now iterate across digits if any, digits should only be in range 0-9
        //traverse string till a nondigit is found or string ends
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
            int digit = (s[i] - '0') * sign;
            if (sign == 1 && (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && digit > INT_MAX % 10)))
            return INT32_MAX; //check for overflow
            if (sign == -1 && (res < INT_MIN / 10 || (res == INT32_MIN / 10 && digit < INT_MIN % 10)))
            return INT32_MIN; //check for underflow
            res = res * 10 + digit; // update res
            i++;
        }

        return res;
    }
    
    bool checkValid(string& cur, int& len) {
        if(cur[len-1] != '.') { return false; }
        string temp = "";
        
        for(int i=len-2; i>=0; i--) {
            if(cur[i] != '.') {
                temp += cur[i];
            }
            
            if(i == 0 || cur[i] == '.') {
                reverse(temp.begin(), temp.end());
                if(temp[0] == '0' && temp.size() > 1) { return false; }
                // ll num = stol(temp);
                int num = myAtoi(temp);
                if(num >= 0 && num <= 255) { temp = ""; } 
                else { return false; }
            }
        }
        
        return true;
    }
    
public:
    void helper(int i, int count, int n, string cur, string& s, vector<string>& ans) {
        if(i == n) {
            if(count == 0) {
                int len = n + 4;
                if(checkValid(cur, len)) {
                    // cur.pop_back();
                    cur[n+4-1] = '\0';
                    ans.push_back(cur);
                }
            }
            return;
        }
        
        cur += s[i];
        
        helper(i+1, count, n, cur, s, ans);
        cur += ".";
        helper(i+1, count-1, n, cur, s, ans);
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if(n > 12) { return ans; }
        helper(0, 4, n, "", s, ans);
        return ans;
    }
};
