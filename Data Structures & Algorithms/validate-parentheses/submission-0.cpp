class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (isOpeningBracket(c)) stk.push(c);
            else if (isClosingBracket(c) && !stk.empty() && isMatchingClosingBracket(stk.top(), c)) {
                stk.pop();
            } else return false;
        }

        return stk.empty();
    }

    bool isOpeningBracket(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool isClosingBracket(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool isMatchingClosingBracket(char c, char d) {
        switch (c) {
            case '(': return d == ')';
            case '[': return d == ']';
            case '{': return d == '}';
            default: return false;
        }
        return false;
    }
};
