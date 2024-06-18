class Solution {
public:
    bool checkValidString(string s) {
        stack<int> ps, ss;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                ps.push(i);
            } else if (s[i] == '*') {
                ss.push(i);
            } else { // s[i] == ')'
                if (!ps.empty()) {
                    ps.pop();
                } else if (!ss.empty()) {
                    ss.pop();
                } else {
                    return false;
                }
            }
        }

        while (!ps.empty() && !ss.empty()) {
            if (ps.top() > ss.top()) {
                return false;
            }
            ps.pop();
            ss.pop();
        }

        return ps.empty();
    }
};