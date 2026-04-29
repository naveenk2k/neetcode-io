class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        unordered_map<char, int> mp;

        int ans = 0;

        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && mp[s[r]] == 0) {
                ans = max(ans, r-l+1);
                
                ++mp[s[r]];
                ++r;
            }
            --mp[s[l]];
        }

        return ans;
    }
};
