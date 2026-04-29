class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> chars(26, 0);
        for (int i = 0; i < (int)s.length(); ++i) {
            ++chars[s[i] - 'a'];
            --chars[t[i] - 'a'];
        }
        for (int c : chars) {
            if (c != 0) return false;
        }
        return true;

    }
};
