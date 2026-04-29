class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) s.insert(n);

        int mx = 0;
        for (int n : nums) {
            if (s.count(n-1) == 0) {
                int cnt = 1;
                int target = n+1;
                while (s.count(target) > 0) {
                    ++cnt;
                    target += 1;
                }
                mx = max(mx, cnt);
            }
        }

        return mx;

    }
};
