class Solution {
public:
    int longestValidParentheses(string str) {
        int left = 0, right = 0, maxi = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxi = max(maxi, left * 2);
            else if (right > left)
                left = 0, right = 0;
        }
        left = 0, right = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxi = max(maxi, left * 2);
            else if (left > right)
                left = 0, right = 0;
        }
        return maxi;
    }
};