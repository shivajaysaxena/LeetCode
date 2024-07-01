class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 1, m = 0;
        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == chars[i - 1]) {
                k++;
            } else {
                chars[m++] = chars[i - 1];
                if (k > 1) {
                    string temp = to_string(k);
                    for (char ch : temp) {
                        chars[m++] = ch;
                    }
                }
                k = 1;
            }
        }
        return m;
    }
};