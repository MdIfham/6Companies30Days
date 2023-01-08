// 149. Max Points on a Line
// Link: https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<double, int> mp;
        int maxi = INT32_MIN;
        
        for(int i=0; i<n; i++) {
        // int i=1; {
            mp.clear();
            for(int j=0; j<n; j++) {
                if(i != j) {
                    double slope = (points[j][1] - points[i][1])/((double)(points[j][0] - points[i][0]));
                    mp[slope]++;
                    maxi = max(maxi, mp[slope] + 1);
                    // cout<<maxi<<" ";
                }
            }
        } 
        
        // cout<<endl;
        
        if(maxi == INT32_MIN) { return 1; }
        return maxi;
    }
};
