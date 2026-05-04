class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0;
        int hi = n - 1;

        // predicate: are you less than or equal to the last element?
        // F, F, F, T, T, T, T. Find the first T - that is the minimum element.
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;

            if ((nums[mid] <= nums[n-1])) hi = mid;
            else lo = mid+1;
        }

        // lo is the minimum element / deflection point. 
        cout << "lo=" << lo << '\n';
        if (nums[lo] == target) return lo;
        else if (target > nums[n-1]) {
            // search in [0...lo-1]
            return binarySearch(nums, 0, lo-1, target);
        } else {
            // search in [lo+1...n-1]
            return binarySearch(nums, lo+1, n-1, target);
        }

        return nums[lo] == target ? lo : -1;
    }

    int binarySearch(vector<int> nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
};
