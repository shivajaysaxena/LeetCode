class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t, freq_s;
        for (int i = 0; i < t.size(); i++) {
            freq_t[t[i]]++;
        }
        int unique = freq_t.size(), utn = 0;
        int l = 0, r = 0, st = 0, size = INT_MAX;
        while (r < s.size()) {
            freq_s[s[r]]++;
            if (freq_s[s[r]] == freq_t[s[r]])
                utn++;
            while (l <= r && utn == unique) {
                if (r - l + 1 < size) {
                    st = l;
                    size = r - l + 1;
                }
                freq_s[s[l]]--;
                if (freq_s[s[l]] < freq_t[s[l]])
                    utn--;
                l++;
            }
            r++;
        }

        if (size != INT_MAX) {
            return s.substr(st, size);
        }
        return "";
    }
};