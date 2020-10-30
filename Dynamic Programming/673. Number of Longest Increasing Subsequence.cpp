class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        if(a.empty())   return 0;
        int n=a.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int lis=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
            if(dp[i]>lis){
                lis=dp[i];
                ans=count[i];
            }
            else if(dp[i]==lis){
                ans+=count[i];
            }
        }
        return ans;
    }
};
