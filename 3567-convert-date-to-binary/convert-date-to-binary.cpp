class Solution {
public:
    string convertDateToBinary(string date) {
        int i = stoi(date.substr(0, 4));
        int j = stoi(date.substr(5, 2));
        int k = stoi(date.substr(8, 2));
        string s = "", n = "", p = "";
        while (i) {
            s = to_string(i & 1) + s;
            i = i >> 1;
        }
        s += '-';
        while (j) {
            p = to_string(j & 1) + p;
            // string s=to_string(i&1)+s;
            j = j >> 1;
        }
        s += p;
        s += '-';
        while (k) {
            n = to_string(k & 1) + n;
            // string s=to_string(i&1)+s;
            k = k >> 1;
        }
        s += n;
        return s;
    }
};