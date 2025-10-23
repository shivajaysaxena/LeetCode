class Solution {
public:
    bool hasSameDigits(std::string s) {
        size_t len = s.size();
        while (len > 2) {
            for (size_t i = 0; i < len - 1; ++i) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            --len;
        }
        return s[0] == s[1];
    }
};