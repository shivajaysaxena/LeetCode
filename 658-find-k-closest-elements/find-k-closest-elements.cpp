class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int h = arr.size() - 1;
        while (h - l >= k) {
            if (x - arr[l] > arr[h] - x) {
                l++;
            } else {
                h--;
            }
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[l++]);
        }
        return ans;
    }
};