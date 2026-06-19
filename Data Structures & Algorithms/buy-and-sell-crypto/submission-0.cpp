class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                mx = max(mx, prices[j]-prices[i]);
            }
        }

        return mx;
    }
};
