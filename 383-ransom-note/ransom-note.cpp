class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26];
        for (int i = 0; i < (int)magazine.size(); ++i)
            ++letters[magazine[i] % 97];
        for (int i = 0; i < (int)ransomNote.size(); ++i)
            --letters[ransomNote[i] % 97];
        for (int i = 0; i < 26; ++i)
            if (letters[i] < 0)
                return false;
        return true;
    }
};