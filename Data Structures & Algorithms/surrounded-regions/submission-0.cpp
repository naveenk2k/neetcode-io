class Solution {
public:

    bool ok(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        board[x][y] = '#';

        vector<vector<int>> dirs = {
            {0, -1}, {0, 1}, {1, 0}, {-1, 0}
        };

        for (vector<int> dir : dirs) {
            int xx = x + dir[0];
            int yy = y + dir[1];

            if (ok(xx, yy, n, m) && board[xx][yy] == 'O') {
                dfs(board, xx, yy);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (board[i][j] == 'O') {
                        // cout << i << "," << j << '\n';
                        dfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
