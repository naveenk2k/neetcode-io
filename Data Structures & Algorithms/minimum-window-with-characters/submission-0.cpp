class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.size();
        int minWindowSize = INT_MAX;
        int minWindowStart = -1;
        int r = 0;
        unordered_map<char, int> mp;

        for (int l = 0; l < n; ++l) {
            // include chars to the right till required
            while(r < n && !charMapContainsString(mp, t)) {
                ++mp[s[r]];
                ++r;
            }

            if (!charMapContainsString(mp, t)) break;

            // Found a satisfying window from [l, r-1] of size (r-1)-l+1=r-l
            cout << "Found a window: " << s.substr(l, r-l) << " that contains: " << t << '\n';

            // check if this window beats previous best
            if (r-l < minWindowSize) {
                minWindowSize = r-l;
                minWindowStart = l;
            }

            for (auto [k, v] : mp) cout << k << "->" << v << '\n';
            cout << "\n\n";

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
