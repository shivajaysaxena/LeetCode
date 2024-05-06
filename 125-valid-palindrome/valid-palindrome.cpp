class Solution {
public:
    bool isPalindrome(string s) {
        string modifiedString;
        for (char c : s) {
            if (isalnum(c)) {
                modifiedString += tolower(c);
            }
        }
        int left = 0;
        int right = modifiedString.length() - 1;
        while (left < right) {
            if (modifiedString[left] != modifiedString[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};