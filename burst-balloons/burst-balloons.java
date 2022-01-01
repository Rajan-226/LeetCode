class Solution {
    public int maxCoins(int[] num) {
        int n=num.length;
        int[] nums=new int[n+2];
        nums[0]=1;
        for(int i=1;i<=n;i++){
            nums[i]=num[i-1];
        }
        nums[n+1]=1;
            
        int[][] dp=new int[n+5][n+5];
        
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i][i]=nums[i];
            ans=Math.max(ans,nums[i]);
        }
        for(int len=1;len<=n;len++){
            for(int left=1;left<=(n-len+1);left++){
                int right=left+len-1;
                for(int k=left;k<=right;k++){
                    int now=nums[k]*nums[left-1]*nums[right+1];
                    now+=dp[left][k-1];
                    now+=dp[k+1][right];

                    dp[left][right]=Math.max(dp[left][right],now);
                    ans=Math.max(ans,now);
                }
            }
        }
        return ans;
    }
}