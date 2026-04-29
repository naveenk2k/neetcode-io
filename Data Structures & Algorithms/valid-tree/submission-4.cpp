class Solution {
public:
    bool hasCycle = false;

    void dfs(vector<vector<int>>& g, vector<bool>& visited, int u, int parent) {
        if (hasCycle) return;

        if (visited[u]) {
            hasCycle = true; 
            return;
        }

        visited[u] = true;

        for (int v : g[u]) {
            if (v == parent) continue; 
            dfs(g, visited, v, u);
        }

    }

    bool validTree(int n, vector<vector<int>>& edges) {
        
        // A tree has n-1 edges, exactly 1 connected component and no cycles

        if (edges.size() != n-1) return false;

        vector<vector<int>> g(n);
        
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            g[u].push_back(v);
            g[v].push_back(u);

        }

        vector<bool> visited(n, false);
        dfs(g, visited, 0, -1);

        for (bool v : visited) {
            if (!v) return false;
        }

        return !hasCycle;
    }
};
