class Solution {
public:
    bool isPerfectSquare(int num) {
        double ans = sqrt(num);
        if (int(ans) == ans) {
            return true;
        }
        return false;
    }
};