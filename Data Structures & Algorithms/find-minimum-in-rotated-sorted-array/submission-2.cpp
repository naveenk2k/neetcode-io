class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = (int)nums.size() - 1;
        int lo = 0;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi-lo)/2;

            // Predicate: nums[i] < nums[n-1]. We have a list of F,F,F,F,T,T,T,T when checking this predicate.
            if (nums[mid] < nums[n]) hi = mid;
            else lo = mid+1;
        }

        return nums[lo];
    }
};
