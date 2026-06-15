class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxArea = 0;

        int n = (int)heights.size();
        int l = 0;
        int r = n-1;

        while (l < r) {
            int height = min(heights[l], heights[r]);
            mxArea = max(mxArea, height * (r-l));
            // cout << mxArea << ' ' << height << '\n';
            if (heights[l] < heights[r]) ++l;
            else --r;
        }

        return mxArea;
    }
};
