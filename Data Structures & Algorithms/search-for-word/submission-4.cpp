class Solution {
public:

    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    bool ok(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool found = false;

    void search(vector<vector<char>>& board, string word, vector<char>& path, int x, int y, vector<vector<bool>>& visited) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        if (found) return;
        
        path.push_back(board[x][y]);
        visited[x][y] = true;

        if (path.size() == word.length()) {
            found = true;
            return;
        }

        for (vector<int> dir : dirs) {
            int xx = x + dir[0];
            int yy = y + dir[1];
            if (ok(xx, yy, n, m) && board[xx][yy] == word[path.size()] && !visited[xx][yy]) {
                search(board, word, path, xx, yy, visited);
            }
        }

        path.pop_back();
        visited[x][y] = false;

    }


    bool exist(vector<vector<char>>& board, string word) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    vector<char> path;
                    search(board, word, path, i, j, visited);
                    if (found) return true;
                }
            }
        }

        return false;
    }
};
