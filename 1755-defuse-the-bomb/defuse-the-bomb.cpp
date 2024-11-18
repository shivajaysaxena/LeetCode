class Solution {
public:
    vector<int> decrypt(vector<int> code, int k) {
        if (k < 0)
            reverse(begin(code), end(code));
        int n = size(code), m = abs(k),
            sum = accumulate(begin(code), begin(code) + m, 0);
        code.insert(end(code), begin(code), begin(code) + m);

        for (int i = 0; i < n; i++)
            code[i] = sum += code[i + m] - code[i];

        code.resize(n);
        if (k < 0)
            reverse(begin(code), end(code));
        return code;
    }
};