class Solution {
public:
    int helper(int mid, vector<int> arr, int m) {
        int n = arr.size();
        int start = arr[0], ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] - start >= mid) {
                ans++;
                start = arr[i];
            }
        }
        if (ans >= m)
            return 1;
        return 0;
    }
    int maxDistance(vector<int>& arr, int m) {
        int maxi = *max_element(arr.begin(), arr.end());
        int low = 1, high = maxi;
        sort(arr.begin(), arr.end());
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (helper(mid, arr, m)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
};