class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;
        int maxi = 0;
        for (const auto& pair : mpp)
            maxi = max(maxi, pair.second);
        int k = 0;
        for (auto it : mpp)
            if (maxi == it.second)
                k++;
        return maxi * k;
    }
};