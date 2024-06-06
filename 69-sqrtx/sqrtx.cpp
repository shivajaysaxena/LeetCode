class Solution {
public:
    int mySqrt(int n) {
        int l=1;
        int h=n;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long val=mid*mid;
            if(val<=n){
                l=mid+1;
            }     
            else{
                h=mid-1;
            }
        }
        return h;
    }
};