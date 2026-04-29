class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = (int)s1.size();
        int l2 = (int)s2.size();

        // abca
        // leca

        // a=2,b=1,c=1 
        // a=1,c=1,e=1,l=1 becomes a=2,c=1,e=1
        // match=1. need match=len(abca)

        vector<int> v1(26, 0), v2(26, 0);

        // window size is fixed (s1.length)
        for (int i = 0; i < l1; ++i) {
                ++v1[s1[i]-'a'];
                ++v2[s2[i]-'a'];
        }

        int matches = 0; // numOfMatchingCharacters
        // Calculate matches in the first subarray/window s2. 
        for (int i = 0; i < 26; ++i) {
            if (v1[i] == v2[i]) ++matches;
        }

        if (matches == 26) return true;

        // Keep moving the window one position to the right and see if any window results in 26 matches.
        for (int i = l1; i <= l2; ++i) {

            char l = s2[i-l1];
            char r = s2[i]; 

            // add r, remove l;

            // if (l != r) {
                --v2[l-'a']; // remove left
                if (v2[l-'a'] == v1[l-'a']) ++matches;
                else if(v2[l-'a'] + 1 == v1[l-'a']) --matches; // because we removed this char and lost a matching pair

                ++v2[r-'a']; // add right
                if(v2[r-'a'] == v1[r-'a']) ++matches;
                else if(v2[r-'a'] - 1 == v1[r-'a']) --matches; // used to be equal before we added right, so now we lost a matching pair

            // }
            
            if (matches == 26) return true;

        }

        return false;
    }
};
