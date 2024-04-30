class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
    int m=mat[0].size();
    int top=0,left=0;
    int bot=n-1,right=m-1;
    vector<int> ans;
    while(top<=bot && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bot;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bot){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bot][i]);
            }
            bot--;
        }
        if(left<=right){
            for(int i=bot;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
    }
};