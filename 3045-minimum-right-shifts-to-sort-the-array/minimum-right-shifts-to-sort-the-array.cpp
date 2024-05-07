class Solution {
public:
    int minimumRightShifts(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; i++) {
            if (arr == sorted) {
                return i;
            }
            int last = arr[n - 1];
            for (int j = n - 1; j > 0; j--) {
                arr[j] = arr[(j - 1 + n) % n];
            }
            arr[0] = last;
        }

        return -1;
    }
};