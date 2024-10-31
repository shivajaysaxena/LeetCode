class Solution {
public:
    int reverse(int x) {
        int n=x;
        long rev=0;
        while(n){
            rev=rev*10+n%10;
            n/=10;
        }
        if(rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        return (int)rev;
    }
};