class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0;
        int l = 0, r = 0;
        int o = 0, z = 0;
        while (r < s.length()) {
            if (s[r] == '1')
                o++;
            else
                z++;
            while (o > k && z > k) {
                if (s[l] == '1')
                    o--;
                else
                    z--;
                l++;
            }
            res += (r - l + 1);
            r++;
        }
        return res;
    }
};