class Solution {
public:
    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expandFromCenter(s, i, i);      // odd
            string even = expandFromCenter(s, i, i + 1); // even

            if (odd.size() > res.size())
                res = odd;
            if (even.size() > res.size())
                res = even;
        }
        return res;
    }
};