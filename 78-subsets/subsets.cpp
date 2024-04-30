class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        for(int i=0;i<nums.size();i++){
            int n=ans.size();
            for(int j=0;j<n;j++){
                vector<int> temp=ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};