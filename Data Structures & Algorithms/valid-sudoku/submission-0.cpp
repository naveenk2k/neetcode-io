class Solution {
public:

    bool isValid(vector<char> nums) {
        set<char> s;
        for (int num : nums) {
            if (num == '.') continue;
            if (num < '1' || num > '9') return false;
            if (s.contains(num)) return false;
            s.insert(num);
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> values;

        // check all rows
        for (int i = 0; i < (int)board.size(); ++i) {
            values.clear();
            for (int j = 0; j < (int)board.size(); ++j) {
                values.push_back(board[i][j]);
            }
            if (!isValid(values)) return false;
        }

        // check all cols
        for (int i = 0; i < (int)board.size(); ++i) {
            values.clear();
            for (int j = 0; j < (int)board.size(); ++j) {
                values.push_back(board[j][i]);
            }
            if (!isValid(values)) return false;
        }

        // check all 3x3
        vector<vector<int>> middles = {
            {1, 1}, {1, 4}, {1, 7},
            {4, 1}, {4, 4}, {4, 7},
            {7, 1}, {7, 4}, {7, 7}
        };

        vector<vector<int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        for (auto middle : middles) {
            values.clear();
            for (auto dir : dirs) {
                values.push_back(board[middle[0] + dir[0]][middle[1] + dir[1]]);
            }
            if (!isValid(values)) return false;
        }
        
        return true;
    }
};
