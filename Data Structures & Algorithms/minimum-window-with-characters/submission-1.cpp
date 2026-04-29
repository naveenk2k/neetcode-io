class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.size();
        int minWindowSize = INT_MAX;
        int minWindowStart = -1;
        unordered_map<char, int> mp; // to store chars of the current window under consideration in string 's'
        int r = 0;

        for (int l = 0; l < n; ++l) {
            // include chars to the right till required
            while(r < n && !charMapContainsString(mp, t)) {
                ++mp[s[r]];
                ++r;
            }

            // Could not find a satisfying window (of any length) starting at position 'l'
            if (!charMapContainsString(mp, t)) break;

            // Found a satisfying window from [l, r-1] of size (r-1)-l+1=r-l
            // cout << "Found a window: " << s.substr(l, r-l) << " that contains: " << t << '\n';

            // check if this window beats previous best
            if (r-l < minWindowSize) {
                minWindowSize = r-l;
                minWindowStart = l;
            }

            --mp[s[l]];
            if (mp[s[l]] == 0) mp.erase(s[l]);
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minWindowStart, minWindowSize);
    }

    bool charMapContainsString(unordered_map<char, int> mp, string t) {
        for (char c : t) {
            if (mp.count(c) == 0) return false;
            --mp[c];
            if (!mp[c]) mp.erase(c);
        }

        return true;
    }
};
