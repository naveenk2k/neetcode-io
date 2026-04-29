class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for (int n : nums) ++frequencies[n];

        vector<vector<int>> frequencyCounts((int)nums.size() + 1);
        for (auto [n, freq] : frequencies) frequencyCounts[freq].push_back(n);
        
        vector<int> res;
        for (int i = (int)frequencyCounts.size()-1; i >= 0; --i) {
            for (int n : frequencyCounts[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
