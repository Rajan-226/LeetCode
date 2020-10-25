class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
