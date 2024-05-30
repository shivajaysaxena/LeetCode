class Solution {
public:
    string fractionToDecimal(int n, int d) {
        long long a = labs(n), b = labs(d);
        string ans = "";
        if ((n < 0 && d > 0) || (n > 0 && d < 0))
            ans += "-";
        long long res = a / b;
        ans += to_string(res);
        long long r = a % b;
        if (r == 0)
            return ans;
        ans += ".";
        unordered_map<int, int> mp;
        mp[r] = ans.length();

        while (r != 0) {
            r *= 10;
            res = r / b;
            ans += to_string(res);
            r = r % b;
            if (mp.find(r) != mp.end()) {
                ans.insert(ans.begin() + mp[r], '(');
                ans += ")";
                return ans;
            }
            mp[r] = ans.length();
        }
        return ans;
    }
};