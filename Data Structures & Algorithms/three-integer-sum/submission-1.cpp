class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            // Look for target in nums[i+1...n-1].
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int sum = nums[j]+nums[k];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j-1]) ++j;
                } else if (sum < target) ++j;
                else --k;
            }
        }

        return res;
    }
};
