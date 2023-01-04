// Link: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    // if the courses can be topologically sorted then there exists no cycle ans all 
    // the courses can be finished
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        for(int i=0; i<numCourses;  i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count=0;
        while(!q.empty()) {
            
            int node = q.front(); q.pop();
            count++;
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(count == numCourses)
            return true;
        else
            return false;
    }
};
