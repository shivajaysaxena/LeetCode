class Solution {
public:
    int forward(int x){
        if((x % 8 == 0) || x % 8 == 1) return 0;
        if((x % 8 == 2) || x % 8 == 3) return x ^ (x + 2) ^ (x + 4);
        if((x % 8 == 4) || x % 8 == 5) return x ^ (x + 2);
        return x;
    }
    int backward(int x){
        if((x % 8 == 0) || x % 8 == 1) return x;
        if((x % 8 == 2) || x % 8 == 3) return x ^ (x - 2);
        if((x % 8 == 4) || x % 8 == 5) return x ^ (x - 2) ^ (x - 4);
        return 0;
    }
    int xorOperation(int n, int start) {
        int s = start, e = start + (2 * (n - 1));

        return forward(s) ^ backward(e);
    }
};