class Solution {
public:

    bool ok(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    vector<vector<int>> dirs = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();


        queue<pair<int, int>> q;

        int freshCount = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) ++freshCount;
            }
        }

        // // [2,2,1],
        //    [2,1,2],
        //    [0,2,2]

        if (!freshCount) return 0;
        
        int minutes = 0;
        while(freshCount > 0 && !q.empty()) {

            ++minutes;
            int N = q.size();
            for (int i = 0; i < N; ++i) {

                auto [x, y] = q.front();
                q.pop();

                for (auto dd : dirs) {
                    int xx = x + dd[0];
                    int yy = y + dd[1];

                    if (ok(xx, yy, n, m) && grid[xx][yy] == 1) {
                        // turn fresh fruit at (xx, yy) to rotten
                        --freshCount;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
        }

        if (freshCount == 0) return minutes;
        else return -1;
    }
};
