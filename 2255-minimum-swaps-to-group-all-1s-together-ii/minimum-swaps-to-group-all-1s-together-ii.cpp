class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> numss = nums;
        int oneCount = 0, n = numss.size();
        for (int i = 0; i < n; i++) {
            oneCount += numss[i];
            numss.push_back(nums[i]);
        }

        int ans = INT_MAX, i = 0, j = 0, windowOneCount = 0;
        while (j < oneCount)
            windowOneCount += numss[j++];
        ans = min(ans, oneCount - windowOneCount);

        while (j < n + n) {
            if (numss[j++])
                windowOneCount++;
            if (numss[i++])
                windowOneCount--;
            ans = min(ans, oneCount - windowOneCount);
        }
        return ans;
    }
};