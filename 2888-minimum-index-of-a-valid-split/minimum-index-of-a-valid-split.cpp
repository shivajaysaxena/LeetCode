class Solution {
public:
    static int minimumIndex(const vector<int>& a) noexcept {
        const int n = a.size();
        int major;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (count == 0)
                major = a[i];
            count += ((major == a[i]) << 1) - 1;
        }
        count = 0;
        for (int i = 0; i < n; ++i)
            count += major == a[i];

        const int n1 = n - 1;
        for (int i = 0, lcount = 0; i < n; ++i) {
            lcount += major == a[i];
            if (lcount > ((i + 1) >> 1) && (count - lcount) > ((n1 - i) >> 1))
                return i;
        }
        return -1;
    }
};