class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const size_t n = A.size();
        vector<int> swap(n, n), no_swap(n, n);
        swap[0] = 1;
        no_swap[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                swap[i] = swap[i - 1] + 1;
                no_swap[i] = no_swap[i - 1];
            }
            
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                swap[i] = min(swap[i], no_swap[i - 1] + 1);
                no_swap[i] = min(no_swap[i], swap[i - 1]);
            }
        }
        
        return min(swap.back(), no_swap.back());
    }
};