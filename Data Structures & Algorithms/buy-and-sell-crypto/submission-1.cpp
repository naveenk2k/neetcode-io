class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit = 0;
        int minBuy = prices[0];
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            mxProfit = max(mxProfit, prices[i]-minBuy);
            minBuy = min(minBuy, prices[i]);
        }

        return mxProfit;
    }
};
