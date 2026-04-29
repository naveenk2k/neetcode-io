class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // F, F, F, T, T, T, T
        int lo = 1;
        int hi = * max_element(piles.begin(), piles.end()); // INT_MAX also works (can avoid extra O(n) to find max element)

        while (lo < hi) {
            int mid = lo + (hi-lo)/2;

            if (canEatAllBananas(piles, h, mid)) hi = mid;
            else lo = mid+1;
        }

        return lo;
    }

    bool canEatAllBananas(vector<int> piles, int h, int k) {
        int hours = 0;
        for (int p : piles) {
            hours += ((p + k - 1) / k); // ceil(p/k)
        }

        return hours <= h;
    }
};
