// Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/

class Solution {
    // Following is the parent And Distance Finder dfs
    void dfs(int u, int p, int d, vector<int>& par, vector<int>& dis, vector<vector<int>>& adj) {
        dis[u] = d;
        par[u] = p;
        for (auto& it : adj[u]) {
            if (it == p) continue;
            dfs(it, u, d + 1, par, dis, adj);
        }
    }

    // This finds the total sum contribution to each node
    int dfs2(int u, int p, vector<int>& amount, vector<vector<int>> &adj) {
        int defAmount = amount[u];
        int maxi = INT32_MIN;
        for (auto& it : adj[u]) {
            if (it != p) {
                maxi = max(maxi, dfs2(it, u, amount, adj));
            }
        }

        // if the node is leaf node we just return its amount
        if (maxi == INT32_MIN) {
            return defAmount;
        }
        else {
            return defAmount + maxi;
        }
    }

public:

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> par(n), dis(n);

        // Calling the parent And Distance Finder dfs 
        dfs(0, 0, 0, par, dis, adj);

        int curNode = bob;
        int bobDistance = 0;
        //update the path of ... from bob to 0
        while (curNode != 0) {
            if (dis[curNode] > bobDistance) {
                amount[curNode] = 0;
            }
            else if (dis[curNode] == bobDistance) {
                amount[curNode] /= 2;
            }
            curNode = par[curNode];
            bobDistance++;
        }

        // Call that gives up maximum amount for Alice
        return dfs2(0, 0, amount, adj);
    }
};
