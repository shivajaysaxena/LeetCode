class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = size(numbers);
        int st=0, et = n-1;
        while(st<et){
            if(numbers[st]+numbers[et]==target){
                return {st+1,et+1};
            }
            else if(numbers[st]+numbers[et]>target){
                et--;
            }
            else if(numbers[st]+numbers[et]<target){
                st++;
            }
        }
        return {};
    }
};