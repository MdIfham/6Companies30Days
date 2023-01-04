// Link: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastIndex = 0;
        
        for(int i =0; i<n; i++) {
            hash[i] = i;
            for(int pi = 0; pi<i; pi++) {
                // if(arr[pi] < arr[i] &&  1 + dp[pi] > dp[i]) {
                if(arr[i] % arr[pi] == 0 &&  1 + dp[pi] > dp[i]) {
                    dp[i] = max(dp[i], 1 + dp[pi]);
                    hash[i] = pi;
                }
            }
            
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis(maxi);
        lis[0] = arr[lastIndex];
        int ind = 1;
        
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis[ind++] = arr[lastIndex];
        }

        reverse(lis.begin(), lis.end());

        // cout<<"Length of LIS is: "<<maxi<<'\n';
        // for(int i=0; i<maxi; i++) {
        //     cout<<lis[i]<<' ';
        // }
        
        return lis;
    }
};
