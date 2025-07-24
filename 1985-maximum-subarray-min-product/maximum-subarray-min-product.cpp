class Solution {
public:
    int mod = (int)1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int index = i;
            while (!st.empty() and nums[st.top()] >= nums[i]) {
                index = left[st.top()];
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = index;
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            int index = i;
            while (!st.empty() and nums[st.top()] >= nums[i]) {
                index = right[st.top()];
                st.pop();
            }

            if (st.empty()) {
                right[i] = -1;
            } else {
                right[i] = index;
            }
            st.push(i);
        }

        long long ans = INT_MIN;

        vector<long long> prefix(n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            prefix[i] = sum;
        }

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            if (left[i] == -1 and right[i] == -1) {
                sum = prefix[n - 1] * nums[i];
            } else if (left[i] == -1) {
                sum = prefix[right[i]] * nums[i];
            } else if (right[i] == -1) {
                sum = (prefix[n - 1] - prefix[left[i] - 1]) * nums[i];
            } else {
                sum = (prefix[right[i]] - prefix[left[i] - 1]) * nums[i];
            }

            ans = max(ans, sum);
        }

        return ans % mod;
    }
};