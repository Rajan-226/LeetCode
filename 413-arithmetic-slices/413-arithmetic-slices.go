func numberOfArithmeticSlices(nums []int) int {
    if len(nums)<3{
        return 0
    }
    ans:=0
    cnt:=0
    dif:=nums[1]-nums[0]
    for i:=2;i<len(nums);i++{
        if (nums[i]-nums[i-1])==dif{
            cnt++
        }else{
            ans+=cnt*(cnt+1)/2
            cnt=0
            dif=nums[i]-nums[i-1]
        }
    }
    ans+=cnt*(cnt+1)/2
    return ans
}