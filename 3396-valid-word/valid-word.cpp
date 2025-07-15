class Solution {
public:
    bool isValid(string word) {
        string vowels = "aeiouAEIOU";
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

        if (word.length() < 3)
            return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (isalnum(c)) {
                if (vowels.find(c) != string::npos) {
                    hasVowel = true;
                } else if (consonants.find(c) != string::npos) {
                    hasConsonant = true;
                }
            } else {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};