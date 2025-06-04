class Solution {
public:
    static string answerString(string& word, int numFriends) {
        if (numFriends == 1)
            return word;
        const int n = word.size(), m = n - numFriends + 1;
        string_view sv(word), sM = sv.substr(0, m);
        for (int i = 1; i < n; i++) {
            const int k0 = min(m, n - i);
            sM = max(sM, sv.substr(i, k0));
        }
        return string(sM);
    }
};