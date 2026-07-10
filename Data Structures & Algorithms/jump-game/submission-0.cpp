class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> possible(n, false);
        possible[0] = true;

        for (int i = 0; i < n; ++i) {
            if (possible[i] && nums[i] > 0) {
                for (int j = 1; i+j <= n && j <= nums[i]; ++j) {
                    possible[i+j] = true;
                }
            }
        }

        // for (int p : possible) cout << p << ' ';
        // cout << '\n';

        return possible[n-1];
    }
};
