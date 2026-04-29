class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two Pointers
        int n = (int)numbers.size();
        int i = 0;
        int j  = n-1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return {i+1, j+1};
            else if (sum < target) ++i;
            else --j;
        }


        // Binary Search
        // for (int i = 0; i < (int)numbers.size(); ++i) {
        //     int need = target - numbers[i];
        //     auto it = lower_bound(numbers.begin() + i, numbers.end(), need);
        //     if (it != numbers.end() && *it == need) {
        //         return {i+1, (int)(it-numbers.begin())+1};
        //     }
        // }
    }
};
