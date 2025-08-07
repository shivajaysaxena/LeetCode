class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0;
        int num = 0;
        int sign = 1; // +1 for '+', -1 for '-'

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                // Save current result and sign
                st.push(res);
                st.push(sign);
                // Reset for sub-expression
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                // Pop sign and then result
                int prev_sign = st.top(); st.pop();
                int prev_res = st.top(); st.pop();
                res = prev_res + prev_sign * res;
            }
            // Ignore spaces
        }

        res += sign * num;
        return res;
    }
};
