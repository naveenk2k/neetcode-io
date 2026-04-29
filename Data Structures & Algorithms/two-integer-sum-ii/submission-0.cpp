class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < (int)numbers.size(); ++i) {
            int need = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i, numbers.end(), need);
            if (it != numbers.end() && *it == need) {
                return {i+1, (int)(it-numbers.begin())+1};
            }
        }
    }
};
