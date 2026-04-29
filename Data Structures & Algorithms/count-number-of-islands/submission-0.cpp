class Solution {
    int n;
    int m;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    bool ok(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;

        for (vector<int> dir : dirs) {
            int xx = x+dir[0];
            int yy = y+dir[1];
            if (ok(xx, yy) && grid[xx][yy] == '1' && !visited[xx][yy]) {
                dfs(xx, yy, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();

        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++cnt;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};
