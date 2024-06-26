class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        string temp = " ";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                temp = " ";
            } else {
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        ans.pop_back();
        return ans;
    }
};