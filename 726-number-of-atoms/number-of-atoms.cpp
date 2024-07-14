class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        map<string, int> m;
        string str;
        int p = 1;
        string num;
        stack<int> st;
        int i = n - 1;
        while (i >= 0) {
            if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else if (s[i] == ')') {
                reverse(num.begin(), num.end());
                int sum = 0;
                if (num.size() == 0) {
                    sum = 1;
                } else {
                    sum = stoi(num);
                }
                p *= sum;
                st.push(sum);
                num.clear();
            } else if (s[i] == '(') {
                p = p / st.top();
                st.pop();
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                str += s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                str += s[i];
                reverse(str.begin(), str.end());
                reverse(num.begin(), num.end());
                int sum = 0;
                if (num.size() == 0)
                    sum = 1;
                else {
                    sum = stoi(num);
                }
                m[str] += p * sum;
                str.clear();
                num.clear();
            }
            i--;
        }
        string ans;
        for (auto it : m) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};