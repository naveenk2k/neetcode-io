class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = (int)nums.size() - 1;
        int lo = 0;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi-lo)/2;

            if (nums[mid] < nums[n]) hi = mid;
            else lo = mid+1;
        }

        return nums[lo];
    }
};
