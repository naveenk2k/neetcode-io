class Solution {
public:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (!isOperator(token)) { 
                s.push(stoi(token));
            } else {
                // pop last 2 from the stack and apply the operation
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                int result;

                switch (token[0]) {
                    case '+': result = lhs + rhs; break;
                    case '-': result = lhs - rhs; break;
                    case '*': result = lhs * rhs; break;
                    case '/': result = lhs / rhs; break;
                }
                s.push(result);
            }
        }
        return s.top();
    }
};
