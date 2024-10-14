class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> max_heap(nums.begin(), nums.end());
        while(k--){
            int largest = max_heap.top();
            max_heap.pop();
            ans+= largest;
            int New = ceil(largest/3.0);
            max_heap.push(New);
        }
        return ans;
    }
};