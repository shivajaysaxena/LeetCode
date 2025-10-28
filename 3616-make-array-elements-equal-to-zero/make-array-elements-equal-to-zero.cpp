class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int prefix=0, cnt=0;
        int sum=reduce(nums.begin(), nums.end(), 0);
        for(int x: nums){
            prefix+=x;
            if (x==0){
                cnt+=2*(2*prefix==sum);
                cnt+=(abs(2*prefix-sum)==1);
            }
        }
        return cnt;
    }
};