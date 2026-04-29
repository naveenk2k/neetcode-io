class Solution {
public:
    int n; // rows
    int m; // cols
    vector<vector<int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    bool ok(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector<vector<bool>> bfs(vector<vector<int>>& grid, vector<vector<int>> startPositions) {
        vector<vector<bool>> visitable(n, vector<bool>(m, false));

        // multi-source bfs
        queue<pair<int, int>> q;
        for (vector<int> pos : startPositions) {
            q.push({pos[0], pos[1]});
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            visitable[x][y] = true;
            for (auto dir : dirs) {
                int xx = x+dir[0];
                int yy = y+dir[1];

                if (ok(xx, yy) && !visitable[xx][yy] && grid[xx][yy] >= grid[x][y]) {
                    q.push({xx, yy});
                }
            }

        }

        return visitable;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = (int)heights.size();
        m = (int)heights[0].size();
        
        // add all pacific locations and run bfs
        vector<vector<int>> startPositions;
        for (int i = 0; i < n; ++i) {
            startPositions.push_back({i, 0});
        }
        for (int j = 1; j < m; ++j) {
            startPositions.push_back({0, j});
        }
        vector<vector<bool>> visitableFromPacific = bfs(heights, startPositions);

        // add all atlantic locations and run bfs
        startPositions.clear();
        for (int i = 0; i < n; ++i) {
            startPositions.push_back({i, m-1});
        }
        for (int j = 0; j < m-1; ++j) {
            startPositions.push_back({n-1, j});
        }
        vector<vector<bool>> visitableFromAtlantic = bfs(heights, startPositions);

        // combine both
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visitableFromPacific[i][j] && visitableFromAtlantic[i][j]) answer.push_back({i, j});
            }
        }

        // cout << answer.size() << '\n';

        return answer;
    }
};
