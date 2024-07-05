class Solution {
private:
    bool checkVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowelCount = 0;
        int maxCount = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count++;
            if (checkVowel(s[i])) {
                vowelCount++;
            }
            if (count > k && vowelCount > 0 && checkVowel(s[i - k])) {
                vowelCount--;
            }

            if (vowelCount == k) {
                return k;
            }

            maxCount = max(maxCount, vowelCount);
        }

        return maxCount;
    }
};