class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;

        unordered_map<int, int> numCount;
        set<pair<long long, int>, greater<pair<long long, int>>> top, bottom;

        long long running_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            long long count = numCount[nums[i]];
            if (count > 0) {
                if (top.count({count, nums[i]}) > 0) {
                    top.erase({count, nums[i]});
                    running_sum -= count * nums[i];
                } else {
                    bottom.erase({count, nums[i]});
                }
            }

            count += 1;
            numCount[nums[i]] = count;
            top.insert({count, nums[i]});
            running_sum += (count)*nums[i];

            if (top.size() > x) {

                auto it_smallest = prev(end(top));
                running_sum -= it_smallest->first * it_smallest->second;
                bottom.insert({it_smallest->first, it_smallest->second});
                top.erase(it_smallest);
            }

            if (i >= k) {
                long long count = numCount[nums[i - k]];
                if (top.count({count, nums[i - k]})) {
                    running_sum -= count * nums[i - k];
                    top.erase({count, nums[i - k]});
                } else {
                    bottom.erase({count, nums[i - k]});
                }

                count -= 1;
                numCount[nums[i - k]] = count;
                if (count > 0) {
                    bottom.insert({count, nums[i - k]});
                }

                if (top.size() < x) {
                    auto it = begin(bottom);
                    if (it != end(bottom)) {
                        running_sum += it->first * it->second;
                        top.insert({it->first, it->second});
                        bottom.erase(it);
                    }
                }
            }

            if (i + 1 >= k) {
                result.push_back(running_sum);
            }
        }
        return result;
    }
};