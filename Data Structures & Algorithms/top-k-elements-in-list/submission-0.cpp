class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, vector<int>, greater<int>> frequencyCounts;
        unordered_map<int, int> frequencies;
        for (int n : nums) ++frequencies[n];
        for (auto [n, freq] : frequencies) frequencyCounts[freq].push_back(n);
        vector<int> frequencyOrder;
        for (auto [freq, values] : frequencyCounts) {
            frequencyOrder.insert(frequencyOrder.end(), values.begin(), values.end());
        }

        return vector<int> (frequencyOrder.begin(), frequencyOrder.begin() + k);
    }
};
