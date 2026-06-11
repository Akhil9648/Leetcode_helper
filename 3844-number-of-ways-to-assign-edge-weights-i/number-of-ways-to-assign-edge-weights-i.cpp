class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    int dfs(int node, int parent, unordered_map<int, vector<int>>& adj) {
        int depth = 0;
        for (int child : adj[node]) {
            if (child == parent) continue;

            depth = max(depth, 1 + dfs(child, node, adj));
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int maxDepth = dfs(1, 0, adj);
        return power(2, maxDepth - 1);
    }
};