class Solution {
public:
    int numSteps(string s) {
        bool check = 0;

        reverse(s.begin(), s.end());
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {

            if (!check) {
                if (s[i] == '0')
                    ans++;
                else {
                    ans += 2;
                    check = 1;
                }

                continue;
            }

            if (s[i] == '0')
                ans += 2;

            else
                ans++;
        }

        if (check)
            ans++;

        return ans;
    }
};