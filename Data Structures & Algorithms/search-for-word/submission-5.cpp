class Solution {
public:

    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    bool ok(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool found = false;

    void search(vector<vector<char>>& board, string word, vector<char>& path, int x, int y) {
        int n = (int)board.size();
        int m = (int)board[0].size();

        if (found) return;
        
        path.push_back(board[x][y]);
        board[x][y] = '#';

        if (path.size() == word.length()) {
            found = true;
            return;
        }

        for (vector<int> dir : dirs) {
            int xx = x + dir[0];
            int yy = y + dir[1];
            if (ok(xx, yy, n, m) && board[xx][yy] == word[path.size()]) {
                search(board, word, path, xx, yy);
            }
        }

        path.pop_back();
        board[x][y] = word[path.size()];

    }


    bool exist(vector<vector<char>>& board, string word) {
        int n = (int)board.size();
        int m = (int)board[0].size();


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    vector<char> path;
                    search(board, word, path, i, j);
                    if (found) return true;
                }
            }
        }

        return false;
    }
};
