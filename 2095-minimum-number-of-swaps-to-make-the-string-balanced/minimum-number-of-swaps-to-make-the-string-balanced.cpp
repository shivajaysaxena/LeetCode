class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int ans = 0;
        int closing = 0, j = n - 1;
        for (int i = 0; i < j; i++) {
            if (s[i] == '[')
                closing--;
            if (s[i] == ']') {
                closing++;
                if (closing > 0) {
                    ans++;
                    while (s[j] != '[')
                        j--;
                    swap(s[i], s[j]);
                    closing -= 2;
                    j--;
                }
            }
        }
        return ans;
    }
};