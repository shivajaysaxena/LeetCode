class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1,0));

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }else{
                dp[0][i]=0;
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=amount;t++){
                unsigned long long nt=dp[i-1][t];
                unsigned long long ta=0;
                if(coins[i]<=t){
                    ta=dp[i][t-coins[i]];
                }
                dp[i][t]=nt+ta;
            }
        }
        return (int)dp[n-1][amount];
    }
};