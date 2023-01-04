Link: https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        int s[10] = {0}, g[10] = {0};
        
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        
        string ans = to_string(bulls);
        ans += "A";
        
        int cows = 0;
        for(int i = 0; i<10; i++) {
            cows += min(s[i], g[i]);
        }
        
        ans += to_string(cows);
        ans += "B";
        
        return ans;
    }
};
