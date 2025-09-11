class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        auto isVowel = [](char ch) {
            string v = "AEIOUaeiou";
            return v.find(ch) != string::npos;
        };

        for (char ch : s) {
            if (isVowel(ch)) vowels.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for (char &ch : s) {
            if (isVowel(ch)) {
                ch = vowels[idx++];
            }
        }
        return s;
    }
};