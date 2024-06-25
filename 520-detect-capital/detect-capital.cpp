class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;
        int small = 0;
        int first = 0;
        for (int i = 0; i < word.size(); i++) {
            if (i == 0) {
                if (word[i] >= 65 && word[i] <= 90)
                    first++;
            }
            if (word[i] >= 97 && word[i] <= 122)
                small++;
            else
                capital++;
        }
        if (first == 1 && capital == 1 && small == word.size() - 1)
            return true;
        if (word.size() == capital && small == 0)
            return true;
        if (word.size() == small && capital == 0)
            return true;

        return false;
    }
};