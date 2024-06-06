class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long total = 0;
            for (long long pile : piles) {
                total = total + ceil((double)pile / mid);
            }
            if (total <= h) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};