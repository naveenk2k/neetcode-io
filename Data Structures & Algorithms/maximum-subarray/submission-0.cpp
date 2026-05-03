class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = -1e9;
        for (int num : nums) {
            sum = max(num, sum + num);
            mx = max(mx, sum);
        }
        return mx;
    }
};
