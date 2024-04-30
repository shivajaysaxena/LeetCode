
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int ans = 0;
        int leftmax = 0, rightmax = 0;
        while (l <= r) {
            if (h[l] <= h[r]) {
                if (h[l] >= leftmax) {
                    leftmax = h[l];
                } else {
                    ans += leftmax - h[l];
                }
                l++;
            } else {
                if (h[r] >= rightmax) {
                    rightmax = h[r];
                } else {
                    ans += rightmax - h[r];
                }
                r--;
            }
        }
        return ans;
    }
};