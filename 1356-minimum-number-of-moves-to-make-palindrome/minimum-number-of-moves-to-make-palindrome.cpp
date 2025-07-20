class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left = 0, right = s.size() - 1;
        int out = 0;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                int r = right - 1;
                while (s[left] != s[r])
                    r--;
                if (r == left) {
                    swap(s[r], s[r + 1]);
                    out++;
                } else {
                    while (r < right) {
                        swap(s[r], s[r + 1]);
                        out++;
                        r++;
                    }
                    left++;
                    right--;
                }
            }
        }

        return out;
    }
};