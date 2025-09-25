class Solution {
public:
    string binary(int n) {
        string ans = "";
        while (n) {
            ans.push_back(n % 2 + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string s, int n) {
        for (int i = n; i >= n / 2; i--) {
            string b = binary(i);
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }
};