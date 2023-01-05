// 396. Rotate Function
// Link: https://leetcode.com/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int F0 = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F0 += i * nums[i];
        }

        // after calculating F(0)
        // F(1) = F(0) + sum - n*nums[n-1]

        int prev = F0, cur;
        int maxi = prev;
        for (int i = 1; i < n; i++) {
            cur = prev + sum - n * nums[n - i];
            maxi = max(maxi, cur);
            prev = cur;
        }

        return maxi;
    }
};
