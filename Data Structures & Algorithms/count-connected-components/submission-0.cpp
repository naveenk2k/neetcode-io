class Solution {
public:

    void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs(v, graph, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n, vector<int>());
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int components = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components;
                dfs(i, graph, visited);
            }
        }

        return components;
    }
};
