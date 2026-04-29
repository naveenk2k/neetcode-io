class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || temperatures[i] <= temperatures[s.top()]) s.push(i);
            else {
                while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                    result[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        return result;
    }
};
