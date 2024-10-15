class Solution {
public:
    long long minimumSteps(string s) {
        int p2 = 0;
        long long res = 0;
        bool b = false;
        for (int p1 = 0; p1 < s.size(); ++p1) {
            if (s[p1] == '0') {
                if (!b) {
                    ++p2;
                } else {
                    res += p1 - p2;
                    ++p2;
                }
            } else {
                b = true;
            }
        }
        return res;
    }
};