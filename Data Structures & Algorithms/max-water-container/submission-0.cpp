class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = (int)h.size();
        int i = 0;
        int j = n-1;
        int maxArea = 0;
        while (i < j) {
            int area = min(h[i], h[j]) * (j-i);
            maxArea = max(maxArea, area);
            if (h[i] < h[j]) ++i;
            else --j;
        }

        return maxArea;
    }
};
