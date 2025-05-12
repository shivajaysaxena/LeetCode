class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1Freq(26, 0), s2Freq(26, 0);

        for (int i = 0; i < s1.length(); ++i) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        for (int i = s1.length(); i < s2.length(); ++i) {
            if (s1Freq == s2Freq)
                return true;

            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i - s1.length()] - 'a']--;
        }

        return s1Freq == s2Freq;
    }
};
