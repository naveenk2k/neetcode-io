class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();

        // F, F, F, F, T, T, T, T
        int lo1 = 0, hi1 = n-1;
        while (lo1 < hi1) {
            int mid1 = lo1 + (hi1-lo1)/2;

            // p(mid): target <= end value of row mid?
            if (target <= matrix[mid1][m-1]) hi1 = mid1;
            else lo1 = mid1+1;
        }

        if (target >= matrix[lo1][0] && target <= matrix[lo1][m-1]) {

            int lo2 = 0, hi2 = m-1;
            while (lo2 <= hi2) {
                int mid2 = lo2 + (hi2-lo2)/2;
                if (matrix[lo1][mid2] == target) return true;
                else if (matrix[lo1][mid2] > target) hi2 = mid2-1;
                else lo2 = mid2+1;
            }
        }
        
        return false;

    }
};
