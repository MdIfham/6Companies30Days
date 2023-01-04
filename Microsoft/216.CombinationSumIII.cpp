// Link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
    vector<vector<int>> res;
    
    void helper(int ind, vector<int>& arr, vector<int>&ds, int k, int &n) {
        if(k == 0 || ind == 9) {
            if(k == 0 && accumulate(ds.begin(), ds.end(), 0) == n) {
                res.push_back(ds);    
            }
            return;
        }
        
        // pick 
        ds.push_back(arr[ind]);
        helper(ind+1, arr, ds, k-1, n);
        // nonPick
        ds.pop_back();
        helper(ind+1, arr, ds, k, n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        
        helper(0, arr, ds, k, n);
        return res;
    }
};
