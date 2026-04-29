class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep track of idx of every char that I encounter.
        // if i find a duplicate

        int n = (int)s.size();
        int len = 0;
        for (int i = 0; i < n; ++i) {
            set<char> st;
            st.insert(s[i]);
            int j = i+1;
            while (j < n && st.count(s[j]) == 0) {
                st.insert(s[j]);
                ++j;
            }
            len = max(len, (int)st.size());
        }

        return len;
    }
};
