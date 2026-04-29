class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.size();
        int minWindowSize = INT_MAX;
        int minWindowStart = -1;
        unordered_map<char, int> mpS, mpT;

        for (char c : t) ++mpT[c];
        int need = (int)mpT.size();
        int have = 0;
        int r = 0;

        for (int l = 0; l < n; ++l) {
            // include chars to the right till required
            while(r < n && have != need) {
                ++mpS[s[r]];
                if (mpS[s[r]] == mpT[s[r]]) ++have;
                ++r;
            }

            // Could not find a satisfying window (of any length) starting at position 'l'
            if (have != need) break;

            // Found a satisfying window from [l, r-1] of size (r-1)-l+1=r-l
            // cout << "Found a window: " << s.substr(l, r-l) << " that contains: " << t << '\n';

            // check if this window beats previous best
            if (r-l < minWindowSize) {
                minWindowSize = r-l;
                minWindowStart = l;
            }

            --mpS[s[l]];
            if (mpS[s[l]] < mpT[s[l]]) --have;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minWindowStart, minWindowSize);
    }
};
