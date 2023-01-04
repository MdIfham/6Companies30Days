Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int msf = INT32_MIN, lsf = INT32_MAX;
        int start = 0, end = 0;

        //from left to right
        for (int i = 0; i < n; i++) {
            msf = max(msf, nums[i]);
            if (msf != nums[i]) {
                end = i;
            }
        }

        // from right to left
        for (int j = n - 1; j >= 0; j--) {
            lsf = min(lsf, nums[j]);
            if (lsf != nums[j]) {
                start = j;
            }
        }

        if (start == end) {
            return 0;
        }
        else {
            return end - start + 1;
        }
    }
};
