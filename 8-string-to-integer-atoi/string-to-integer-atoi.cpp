class Solution {
public:
    int myAtoi(string s) {
        if (s.empty())
            return 0;
        int i = 0, sign = 1;
        long ans = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        while (i < s.length()) {
            if (s[i] >= 48 && s[i] <= 57) {
                ans = (ans * 10) + (s[i++] - '0');
            } else
                return ans * sign;

            if (ans > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return ans * sign;
    }
};