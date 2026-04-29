class Solution {
    int n;
    int m;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:

    bool isPacific(int x, int y) {
        return x < 0 || y < 0;
    }
    
    bool isAtlantic(int x, int y) {
        return x >= n || y >= m;
    }

    bool ok(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool canFlow(int X, int Y, vector<vector<int>>& heights) {

        bool pacific = false;
        bool atlantic = false;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({X, Y});
        // cout << "starting from: " << X << "," << Y << '\n';
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            // cout << "At: " << x << "," << y << '\n';
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (vector<int> dir : dirs) {
                int xx = x+dir[0];
                int yy = y+dir[1];

                // cout << "Want to go to: " << xx << "," << yy << '\n';

                if (isPacific(xx, yy)) {
                    pacific = true;
                    // cout << "Reached pacific!" << '\n';
                }
                if (isAtlantic(xx, yy)) {
                    atlantic = true;
                    // cout << "Reached atlantic!" << '\n';
                }

                if (pacific && atlantic) {
                    // cout << "Reached both!" << '\n';
                    return true;
                }

                if (ok(xx, yy) && heights[x][y] >= heights[xx][yy] && !visited[xx][yy]) {
                    // cout << "Will go to: " << xx << "," << yy << '\n';
                    q.push({xx, yy});
                }
            }
        }
        
        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = (int)heights.size();
        m = (int)heights[0].size();
        vector<vector<int>> res;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (canFlow(i, j, heights)) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
