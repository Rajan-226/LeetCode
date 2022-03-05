func max(a int, b int) int{
    if a>b{
        return a
    }
    return b
}

func deleteAndEarn(nums []int) int {
    dp:=make([]int,10010)
    freq:=make([]int,10010)
    for i:=0;i<len(nums);i++{
        freq[nums[i]]++
    }
    n:=10005
    ans:=0
    for i:=1;i<=n;i++{
        //take it
        dp[i+2]=freq[i]*i+dp[i]
        
        
        //don't take it
        dp[i+1]=max(ans,dp[i+1])
        
        
        ans=max(ans,dp[i+2])
    }
    
    return ans
}