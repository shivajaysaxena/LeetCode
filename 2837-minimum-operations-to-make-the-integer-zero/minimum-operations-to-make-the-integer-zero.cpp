
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int x = 1 ; 
        while(true){
            long long xb = 1LL * x * num2 ; 
            long long P = 1LL*num1 - xb ; 
            if(P < x) break; 
            int sb = __builtin_popcountll(P) ; 
            if(sb <= x){
                return x ;
            }
            x++ ;
        }
        return -1 ;
    }
};