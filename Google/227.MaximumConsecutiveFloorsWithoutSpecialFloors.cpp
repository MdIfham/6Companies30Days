// 2274. Maximum Consecutive Floors Without Special Floors
// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int ans = 0;
        
        ans = max(ans, special[0]-bottom);
        ans = max(ans, top-special[n-1]);
        
        for(int i=1; i<n; i++) {
            ans = max(ans, special[i]-special[i-1]-1);
        }
        
        return ans;
    }
};
