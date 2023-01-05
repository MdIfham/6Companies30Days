// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

using ll = long long int;

class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // the adjaceny list for the graph
        vector<pair<ll, ll>> adj[n];
        ll ans = 0;
        
        // building the adjacency list
        // u v and the distance between them
        for(auto &it: roads) {
            ll u = it[0], v = it[1], t = it[2];
            // undirected graph
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        // to store the minimum distance required to reach a node
        vector<ll> distTo(n, 1e18);
        // a minimum priority queue of {distTo, node}
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        // dp array to store the number of ways of reaching a node following the shortest distance
        vector<ll> dp(n, 0);
        // Initialisations
        distTo[0] = 0;
        pq.push({0, 0});
        dp[0] = 1; // there is one way to reach source node 0...i.e, we will start from that only       
        
        while(!pq.empty()) {
            ll distTill = pq.top().first;
            ll u = pq.top().second;
            pq.pop();

            // Not traversing the adjacency of a node whose distTo[node] < distTill 
            // where distTo[node] is smallerest distance till now, 
            // while distTill is the distance popped just right now
            if(distTo[u] < distTill) { continue; }
            
            for (auto& it : adj[u]) {

                ll v = it.first;
                ll newDist = distTill + it.second;

                // if (v == n - 1) {
                //     if (distTo[v] == newDist) {
                //         ans = (ans + 1) % mod;
                //     }
                //     else if (distTo[v] > newDist) {
                //         distTo[v] = newDist;
                //         pq.push({ distTo[v], v });
                //         ans = 1;
                //     }
                // }
                
                if(distTo[v] == newDist) {
                    dp[v] = (dp[v] + dp[u])%mod;
                }
                if (distTo[v] > newDist) {
                    distTo[v] = distTill + it.second;
                    dp[v] = dp[u]%mod;
                    pq.push({ distTo[v], v });
                }
            }            
        }
        
        return dp[n-1];
    }
};
