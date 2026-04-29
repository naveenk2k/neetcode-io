class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> sublists;
        for (string s : strs) {
            vector<int> chars(26, 0);
            for (char c : s) ++chars[c-'a'];
            sublists[chars].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto const& [k, v]: sublists) {
            ans.push_back(v);
        }

        return ans;
    }
};
