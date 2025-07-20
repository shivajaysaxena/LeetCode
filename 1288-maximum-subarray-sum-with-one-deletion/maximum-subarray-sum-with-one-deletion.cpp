class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        long long nodel = arr[0];     // no deletion
        long long onedel = LLONG_MIN; // one deletion
        long long maxi = arr[0];

        for (int i = 1; i < n; i++) {
            if (onedel != LLONG_MIN)
                onedel = max(onedel + arr[i], nodel);
            else
                onedel = nodel; // this means we "delete" current element

            nodel = max((long long)arr[i], nodel + arr[i]);
            maxi = max(maxi, max(nodel, onedel));
        }

        return (int)maxi;
    }
};