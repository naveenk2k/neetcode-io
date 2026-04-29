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
            // Include chars to the right till required
            while(r < n && have != need) {
                ++mpS[s[r]];
                if (mpS[s[r]] == mpT[s[r]]) ++have;
                ++r;
            }

            // If have == need, we have found a satisfying window from [l, r-1] of size (r-1)-l+1=r-l
            // cout << "Found a window: " << s.substr(l, r-l) << " that contains: " << t << '\n';

            // Now, check if this window beats previous best
            if (have == need && r-l < minWindowSize) {
                minWindowSize = r-l;
                minWindowStart = l;
            }

            // Shift the window to the right either to optimise this current good window or to start looking for a new window
            --mpS[s[l]];
            if (mpS[s[l]] < mpT[s[l]]) --have;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minWindowStart, minWindowSize);
    }
};
