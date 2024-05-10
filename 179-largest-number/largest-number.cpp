class Solution {
public:
    static bool comp(int a, int b) {
        string a_s = to_string(a);
        string b_s = to_string(b);

        return (a_s + b_s) > (b_s + a_s);
    }
    string largestNumber(vector<int>& nums) {
        string st = "";
        sort(nums.begin(), nums.end(), comp);

        for (int el : nums) {
            st += to_string(el);
        }

        int n = st.size();
        int i = 0;

        while (i < n - 1 and st[i] == '0') {
            i++;
        }

        return st.substr(i);
    }
};
