class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int mx = 1;
        unordered_set<char> chars(s.begin(), s.end());

        for (char c : s) {
            // find the longest substring of only 'c's
            int len = 1;
            for (int l = 0; l < n; ++l) {
                int r = l;
                int used = 0;
                while (r < n) {
                    if (s[r] == c) {
                        len = max(len, r-l+1);
                        ++r;
                    } else if (used < k) {
                        ++used;
                        len = max(len, r-l+1);
                        ++r;
                    } else {
                        break;
                    }
                }

                // release s[l]
                if (s[l] != c) ++used;
            }
            mx = max(mx, len);
        }
        return mx;
    }
};
