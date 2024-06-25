class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> v;
        for (int i = 0; i < op.size(); i++) {
            int n = v.size();
            if (op[i] == "+")
                v.push_back(v[n - 1] + v[n - 2]);
            else if (op[i] == "C")
                v.pop_back();
            else if (op[i] == "D")
                v.push_back(2 * v[n - 1]);
            else
                v.push_back(stoi(op[i]));
        }
        int sum = 0;
        for (auto s : v)
            sum += s;
        return sum;
    }
};