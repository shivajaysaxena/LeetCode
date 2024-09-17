class Solution {
public:
    int majorityElement(vector<int>& arr) {
       int freq=0;
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            if(freq == 0){
                ans=arr[i];
            }
            if(ans == arr[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans; 
    }
};