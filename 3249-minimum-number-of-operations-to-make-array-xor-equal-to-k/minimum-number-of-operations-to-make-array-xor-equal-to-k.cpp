class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xor1 = 0;
        int out = 0;
        for(auto ele:nums) xor1 = (xor1^ele);
        while(k || xor1){
            if((k&1) != (xor1&1)) out++;
            k = k >> 1;
            xor1 = xor1 >> 1;
        }
        return out;
    }
};