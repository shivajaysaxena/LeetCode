class Solution {
public:
    bool checkPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] == s[end]) {
                start++, end--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0;
        int len = s.length();
        int end = len - 1;

        while (start <= end) {
            if (s[start] == s[end]) {
                start++, end--;
            } else {
                bool ans1 = checkPalindrome(s, (start + 1), end);
                bool ans2 = checkPalindrome(s, start, (end - 1));

                return ans1 || ans2;
            }
        }
        return true;
    }
};