class Solution {
public:

    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };

    bool ok(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        if (!ok(i, j, board.size(), board[0].size()) || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        
        for (auto [dx, dy] : dirs) {
            if (dfs(board, word, i + dx, j + dy, idx + 1)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        vector<string> found;
        unordered_set<string> wordSet(words.begin(), words.end());

        for (const string& word : wordSet) {
            bool wordFound = false;
            for (int i = 0; i < n && !wordFound; ++i) {
                for (int j = 0; j < m && !wordFound; ++j) {
                    if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                        found.push_back(word);
                        wordFound = true;
                    }
                }
            }
        }

        return found;
    }
};