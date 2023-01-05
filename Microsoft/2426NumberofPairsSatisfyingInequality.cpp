// 2426. Number of Pairs Satisfying Inequality
// Link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/submissions/

// This probelm can also be solved using segment tree.

#define ll long long
class Solution {

    ll count(int l, int m, int r, vector<int>& nums, int diff) {
        ll valCount = 0;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j] + diff) {
                valCount += (r - j + 1);
                i++;
            }
            else {
                j++;
            }
        }

        sort(nums.begin() + l, nums.begin() + r + 1);
        // SORT USING TWO POINTERS NOT WORKING
        // sort using two pointers START
//         vector<int> temp(r - l + 6);
//         int k = 0;
//         i = l, j = m + 1;
//         while ((i <= m) && (j <= r)) {
//             if (nums[i] <= nums[j]) {
//                 temp[k++] = nums[i++];
//             }
//             else {
//                 temp[k++] = nums[j++];
//             }
//         }

//         while (i <= m) { temp[k++] = nums[i++]; }
//         while (j <= r) { temp[k++] = nums[j++]; }

//         for (int i = l; i <= r; i++) {
//             nums[i] = temp[i];
//         }
        // sort using two pointers END

        return valCount;
    }

    ll countValidPairs(int l, int r, vector<int>& nums, int diff) {
        if (l == r) return 0;

        int m = (l + r) >> 1;
        ll result = countValidPairs(l, m, nums, diff);
        result += countValidPairs(m + 1, r, nums, diff);

        result += count(l, m, r, nums, diff);
        return result;
    }

public:

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = nums1[i] - nums2[i];
        }

        // Now the problem  has been reduced to find i , j 
        // such that 0 <= i < j <= n - 1 and
        // c[i] <= c[j] + diff

        return countValidPairs(0, n - 1, nums, diff);
    }
};
