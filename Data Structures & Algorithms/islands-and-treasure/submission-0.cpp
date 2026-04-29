class Solution {
    const long long INF = 2147483647;
    int n;
    int m;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool ok(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int bfs(int x, int y, vector<vector<int>>& grid) {
        vector<vector<int>> dist(n, vector<int>(m, INF));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[x][y] = true;

        queue<pair<int, int>> q;
        q.push({x, y});
        dist[x][y] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (vector<int> dir : dirs) {
                int uu = u+dir[0];
                int vv = v+dir[1];
                if (!ok(uu, vv) || visited[uu][vv] || grid[uu][vv] == -1) continue;
                
                if (grid[uu][vv] == 0)
                    return dist[u][v] + 1;
                
                visited[uu][vv] = true;
                dist[uu][vv] = min(dist[uu][vv], dist[u][v] + 1);
                q.push({uu, vv});
            }
        }
        
        return dist[x][y];
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == INF) {
                    grid[i][j] = bfs(i, j, grid);
                }
            }
        }

    }
};
