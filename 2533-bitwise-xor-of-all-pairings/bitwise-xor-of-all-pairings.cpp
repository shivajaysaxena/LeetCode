class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int xor1 = 0, xor2 = 0, ans = 0;
        for (int& x : nums1)
            xor1 ^= x;
        for (int& y : nums2)
            xor2 ^= y;
        if (n % 2 && m % 2 == 0)
            ans = xor2;
        else if (n % 2 == 0 && m % 2)
            ans = xor1;
        else if (n % 2 && m % 2)
            ans = xor1 ^ xor2;
        return ans;
    }
};