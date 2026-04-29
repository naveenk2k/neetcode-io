class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();

        vector<int> ans;
        multiset<int, greater<int>> s;

        for (int i = 0; i < k; ++i) s.insert(nums[i]);
        ans.push_back(*s.begin());

        for (int i = k; i < n; ++i) {
            // remove left edge
            s.erase(s.find(nums[i-k]));
            // insert right edge
            s.insert(nums[i]);
            // compute max
            ans.push_back(*s.begin());
        }

        return ans;
    }
};
