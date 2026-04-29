class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap, tMap;
        for (char c : s) {
            ++sMap[c];
        }
        for (char c : t) {
            ++tMap[c];
        }
        for (char c : s) {
            if (sMap[c] != tMap[c]) return false;
        }
        for (char c : t) {
            if (sMap[c] != tMap[c]) return false;
        }
        return true;

    }
};
