class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> l(n+1, 1), r(n+1, 1);
        for (int i = 0; i < n; ++i) {
            l[i+1] = nums[i] * l[i];
        }
        for (int i = n-1; i >= 0; --i) {
            r[i] = nums[i] * r[i+1];
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(l[i] * r[i+1]);
        }
        return res;
    }
};
