class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k){
                cout<<k<<endl;
                k++;
                cout<<k<<endl;
        }
            else
                break;
        }
        return k;
    }
};