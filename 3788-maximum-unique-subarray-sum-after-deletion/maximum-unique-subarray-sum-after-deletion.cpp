class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int mxmin=INT_MIN;
        set<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                st.insert(nums[i]);
            }
            else{
                mxmin=max(mxmin,nums[i]);
            }
        }
        if(st.size()){
            int sum=0;
            for(auto& it:st){
                sum+=it;
            }
            return sum;
        }
        return mxmin;
    }
};