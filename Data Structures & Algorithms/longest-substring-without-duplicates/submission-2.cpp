class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep track of idx of every char that I encounter.
        // if i find a duplicate

        int n = (int)s.size();
        if (n <= 1) return n;

        int len = 0;
        map<char, int> mp;
        mp[s[0]] = 0;
        for (int i = 0, j = i+1; i < n && j < n;) {
            if (mp.count(s[j]) == 0 || mp[s[j]] < i) {
                mp[s[j]] = j;
                len = max(len, j-i+1);
                ++j;
            } else {
                i = mp[s[j]] + 1;
                mp[s[j]] == j;
            }
        }
        return len;
    }
};
