class Solution {
public:

    string encode(vector<string>& strs) {
        // Convert each string to: len(string) + # + string
        // Need the # to handle len(string) > 9 so that when decoding, we read the length until we reach a '#' char.
        string s = "";
        for (string str : strs) {
            s += (to_string((int)str.length()) + '#' + str);
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            string len = "";
            int j = i;
            while (s[j] != '#') {len += s[j++];}
            
            // s[j] = '#'. Read 'len' more chars and add to strs
            int l = stoi(len);
            
            string str = "";
            i = ++j;
            while (i < j + l) {
                str += s[i++];
            }
            strs.push_back(str);
        }

        return strs;
    }
};
