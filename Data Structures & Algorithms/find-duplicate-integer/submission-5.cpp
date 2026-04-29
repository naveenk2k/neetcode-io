class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i])-1;
            if (nums[idx] < 0) return abs(nums[i]);
            nums[idx] = -nums[idx];

            // [1, 3, 4, 2, 2]
            // i=1, idx=0, [-1, 3, 4, 2, 2] 
            // i=2, idx=1, [-1, -3, 4, 2, 2]
            // i=3, idx=2, [-1, -3, -4, 2, 2]
            // i=4, idx=3, [-1, -3, -4, -2, 2]
            // i=5, idx=4, 
        }
        return -1;
    }
};
