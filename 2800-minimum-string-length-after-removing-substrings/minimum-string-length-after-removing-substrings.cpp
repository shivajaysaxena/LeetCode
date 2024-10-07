class Solution {
public:
    int minLength(string s) {
        if (s.empty()) {
            return 0;
        }
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            if (!st.empty() && ((s[i] == 'B' && st.top() == 'A') ||
                                (s[i] == 'D' && st.top() == 'C'))) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};