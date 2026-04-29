class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) s.insert(n);

        int maxLen = 0;
        for (int n : s) {
            if (s.count(n-1) == 0) {
                int len = 1;
                int target = n+1;
                while (s.count(target) > 0) {
                    ++len;
                    ++target;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;

    }
};
