class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1,2,2,3,3,3,4,4,5
        // numToFreqMap: [(1: 1), (2: 2), (3: 3), (4: 2), (5: 1)]
        // freqToNumsMap: [[(1: 1, 5), (2: 2, 4), (3: 3)]]

        unordered_map<int, int> numToFreqMap;
        map<int, set<int>, greater<int>> freqToNumsMap;

        for (int num : nums) {
            // increment freq of this number
            int prevFreq = numToFreqMap[num];
            ++numToFreqMap[num];
            
            int newFreq = numToFreqMap[num];
            // remove old freq
            freqToNumsMap[prevFreq].erase(num);

            freqToNumsMap[newFreq].insert(num);
        }

        vector<int> ans;
        for (auto [freq, vals] : freqToNumsMap) {
            while (k && !vals.empty()) {
                ans.push_back(*vals.begin());
                vals.erase(vals.begin());
                --k;
            }
        }
        return ans;
    }
};
